/******************************************************************************
| includes
|----------------------------------------------------------------------------*/
#include "ysSCI.h"

void InitSCIB()
{
	ScibRegs.SCICCR.bit.STOPBITS = 1; // 1λֹͣλ
	ScibRegs.SCICCR.bit.PARITY = 0; // ��У��
	ScibRegs.SCICCR.bit.PARITYENA = 0; // ��ֹ��żУ��
	ScibRegs.SCICCR.bit.LOOPBKENA = 0; // �����Բ�ģʽ
	ScibRegs.SCICCR.bit.ADDRIDLE_MODE = 0; // ������ģʽ
	ScibRegs.SCICCR.bit.SCICHAR = 7; // ��λ����

	ScibRegs.SCICTL1.bit.RXERRINTENA = 0; // ���ν��ܴ����ж�
	ScibRegs.SCICTL1.bit.TXWAKE = 0; // ������
	ScibRegs.SCICTL1.bit.SLEEP = 0; // ��˯��״̬
	ScibRegs.SCICTL1.bit.TXENA = 1; // ����ʹ��
	ScibRegs.SCICTL1.bit.RXENA = 1; // ����ʹ��

	//ScibRegs.SCIHBAUD = 0x0000;  // 115200 baud @LSPCLK = 37.5MHz.
	//ScibRegs.SCILBAUD = 0x0028;
	//ScibRegs.SCIHBAUD = 0x0000;  // 38400 baud @LSPCLK = 37.5MHz.
	//ScibRegs.SCILBAUD = 0x0079;
	//ScibRegs.SCIHBAUD = 0x0001;  // 9600 baud @LSPCLK = 37.5MHz.
	//ScibRegs.SCILBAUD = 0x00E7;
	ScibRegs.SCIHBAUD = 0x0007;  // 2400 baud @LSPCLK = 37.5MHz.
	ScibRegs.SCILBAUD = 0x00A0;

	ScibRegs.SCICTL2.bit.RXBKINTENA = 0; // ��ֹRXRDY\BRKDT�ж�
	ScibRegs.SCICTL2.bit.TXINTENA = 0; // ��ֹTXRDY�ж�

	ScibRegs.SCIFFTX.bit.SCIFFENA = 1; // SCI FIFO��
	ScibRegs.SCIFFTX.bit.SCIRST = 1; // SCI FIFO�ܼ������ͽ���
	ScibRegs.SCIFFTX.bit.TXFIFOXRESET = 1; // ����ʹ�ܷ���FIFO
	ScibRegs.SCIFFTX.bit.TXFFINTCLR = 1; // ���TXFFINT��־λ
	ScibRegs.SCIFFTX.bit.TXFFIENA = 0; // ��ֹTX FIFO�ж�
	ScibRegs.SCIFFTX.bit.TXFFIL = 2; // ����FIFO�����Ϊ2

	ScibRegs.SCIFFRX.bit.RXFFOVRCLR = 1; // ���RXFFOVF��־λ
	ScibRegs.SCIFFRX.bit.RXFIFORESET = 1; // ����ʹ�ܽ���FIFO
	ScibRegs.SCIFFRX.bit.RXFFINTCLR = 1; // ���RXFFINT��־λ
	ScibRegs.SCIFFRX.bit.RXFFIENA = 0; // ��ֹRX FIFO�жϣ����ò�ѯ��ʽ��
	ScibRegs.SCIFFRX.bit.RXFFIL = 2; // ����FIFO�����Ϊ2

	ScibRegs.SCIFFCT.bit.ABD = 0; // ���Զ����
	ScibRegs.SCIFFCT.bit.CDC = 0; // ��ֹ�������Զ�����У׼
	ScibRegs.SCIFFCT.bit.FFTXDLY = 0; // FIFO�����ӳ�Ϊ0��

	ScibRegs.SCICTL1.bit.SWRESET = 1; // ȡ�������λ״̬
}

/* =================��������================== */
// ���͵�������
int scib_tx(int a)
{
//    while (ScibRegs.SCIFFTX.bit.TXFFST == 16) {return 0;}
//    ScibRegs.SCITXBUF=a;
//    return 1;
	if(ScibRegs.SCICTL2.bit.TXRDY)
	{
		ScibRegs.SCITXBUF=a;
		return 1;
	}
	else
		return 0;
}

// ����һ������
void scib_str_tx(char * msg)
{
    int i = 0;
    int flag = 1;
    while(msg[i] != '\0')
    {
        flag = scib_tx(msg[i]);
        i++;
		if (flag == 0) break;
    }
}

void scib_num_tx(int msg[])
{
	int i = 0;
	int flag = 1;

	for (i = 0; i < SCINumSend; i++)
	{
		flag = scib_tx(msg[i]);
		if (flag == 0) break;
	}
}

/* =================��������================== */
int scib_rx(int *a)
{
//	if(ScibRegs.SCIRXST.bit.RXRDY)
//	{
//		*a = ScibRegs.SCIRXBUF.bit.RXDT;
//		return 1;
//	}
//	else
//		return 0;
	*a = ScibRegs.SCIRXBUF.bit.RXDT;
	return 1;
}
void scib_str_rx(char *msg)
{

}
void scib_num_rx(int msg[])
{

}
