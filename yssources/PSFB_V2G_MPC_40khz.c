/******************************************************************************
| includes
|----------------------------------------------------------------------------*/
#include "PSFB_V2G_MPC_40khz.h"

/******************************************************************************
| local variable definitions
|----------------------------------------------------------------------------*/
double mSample[5];
int S1_min = 0, S2_min = 0, S3_min = 0, S4_min = 0;
double Udc_IN = 0, Udc_M = 0;
double cost_min = 0;

Uint16 LegCount = 0;  // �ж��ж�ʱ���Ƶ�����ű�
int code_start = 0;
int indexDA = 0;
int variables_flag = 0;  // 0�������������� 1����DAѡ��
int received_data = 0;  // RXFIFO������

/******************************************************************************
@brief  Main
******************************************************************************/
void main()
{
   InitSysCtrl();

   DINT;

   InitPieCtrl();

   IER = 0x0000;
   IFR = 0x0000;

   InitPieVectTable();

   EALLOW;
   PieVectTable.EPWM3_INT = &epwm3_timer_isr;  // ePWM1�ж����
   PieVectTable.TINT0 = &ISRTimer0;
   EDIS;

   InitPORT();
   InitPWM();
   InitECAP();
   InitADC();
   InitCpuTimers();  // ����ת�ٺ�ת�ٸ���ֵ

   ConfigCpuTimer(&CpuTimer0, 150, 5000);  // 5ms
   CpuTimer0Regs.TCR.all = 0x4001; // Use write-only instruction to set TSS bit = 0

   IER |= M_INT3;  // enable ePWM CPU_interrupt
   IER |= M_INT1;  // CpuTimer

   PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
   PieCtrlRegs.PIEIER3.bit.INTx3 = 1;  // enable ePWM1 pie_interrupt

   EINT;   // ���ж� INTM ʹ��
   ERTM;   // Enable Global realtime interrupt DBGM


   int i;
   for(; ;)
   {
	   asm("NOP");
	   for(i=1;i<=10;i++)
	   {}
   }

}

interrupt void epwm3_timer_isr(void)
{
	int S1 = 0, S2 = 0, S3 = 0, S4 = 0;
	double Uan = 0, Ubn = 0, Ucn = 0;
	double ia_temp = 0, ib_temp = 0, ic_temp = 0, ig_temp = 0;
	double cost = 0, cost_min = 1e6;
	double iabc_cmd = 0, ig_cmd = 0;

	// Clear INT flag for this timer
	EPwm3Regs.ETCLR.bit.INT = 1;

	/* ======== ��ѹ�������� ======== */
	ParallelRD(mSample, 5);
	//Ug = LPfilter(mSample[1] * HallRatioVg, Ug, 5000, MPC_Ts);  // �����������������ͬ
	Ug = (Ug + 16.875 * mSample[1]) * 0.888888888889; // y = (lasty + ts * wc * x) / (1 + ts * wc);
	//Udc_IN = LPfilter(mSample[4] * HallRatioVg, Udc_IN, 5000, MPC_Ts);
	Udc_IN = (Udc_IN + 16.875 * mSample[4]) * 0.888888888889;
	Ia = mSample[0] * HallRatioIa;
	Ib = mSample[2] * HallRatioIb;
	Ig = mSample[3] * HallRatioIg;
	Ic = Ig - Ib - Ia;

	Udc_M = 2.52 * (Udc_IN - 2);
	//IabcRefRatio = IgRefRatio * 0.33333333;
	iabc_cmd = Ug * IabcRefRatio;
	ig_cmd = Ug * IgRefRatio;

	int i = 0;
	for(i = 0; i < 16; i++)
	{
		S4 = (i >> 3) & 1;
		S3 = (i >> 2) & 1;
		S2 = (i >> 1) & 1;
		S1 = i & 1;

		Uan = (S1 - S4) * Udc_M - Ug;
		Ubn = (S2 - S4) * Udc_M - Ug;
		Ucn = (S3 - S4) * Udc_M - Ug;
		ia_temp = Ia + (Uan - Ia * Rs) * 0.0014450867;  // 0.0014450867 = 1 / Lls * Ts;
		ib_temp = Ib + (Ubn - Ib * Rs) * 0.0014450867;
		ic_temp = Ic + (Ucn - Ic * Rs) * 0.0014450867;
		ig_temp = ia_temp + ib_temp + ic_temp;
		cost = 3 * fabs(ig_cmd - ig_temp) + fabs(iabc_cmd - ia_temp)\
			 + fabs(iabc_cmd - ib_temp) + fabs(iabc_cmd - ic_temp);
		if(cost < cost_min)
		{
		  S4_min = S4; S3_min = S3; S2_min = S2; S1_min = S1;
		  cost_min = cost;
		}
	}

	EPwm3Regs.CMPA.half.CMPA = S4_min * MPCperiod;  // �Ĵ�������

	EPwm4Regs.CMPA.half.CMPA = S1_min * MPCperiod;  // �Ĵ�������
	EPwm5Regs.CMPA.half.CMPA = S2_min * MPCperiod;  // �Ĵ�������
	EPwm6Regs.CMPA.half.CMPA = S3_min * MPCperiod;  // �Ĵ�������

//	switch(indexDA)
//	{
//		case 0:{DACout(0, Ig); DACout(2, Ug * 0.1); break;}
//		case 1:{DACout(0, Ia); DACout(1, Ia_cmd); DACout(2, Ua_cmd); break;}
//		case 2:{DACout(0, Ib); DACout(1, Ib_cmd); DACout(2, Ub_cmd); break;}
//		case 3:{DACout(0, Ic); DACout(1, Ic_cmd); DACout(2, Uc_cmd); break;}
//		default:{DACout(0, Ug * 0.1); DACout(1, 0);}
//	}

   // Acknowledge this interrupt to receive more interrupts from group 3
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void ISRTimer0(void)
{
	CpuTimer0.InterruptCount ++;
	if (CpuTimer0.InterruptCount  > 15) CpuTimer0.InterruptCount -= 16;

	// Acknowledge this interrupt to receive more interrupts from group 1
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
	CpuTimer0Regs.TCR.bit.TIF=1;
	CpuTimer0Regs.TCR.bit.TRB=1;
}
