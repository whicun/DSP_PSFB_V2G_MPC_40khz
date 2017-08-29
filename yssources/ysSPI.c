/******************************************************************************
| includes
|----------------------------------------------------------------------------*/
#include "ysSPI.h"

void InitSPI()
{
	SpiaRegs.SPICCR.bit.CLKPOLARITY = 0;  //������������������½�������
	SpiaRegs.SPICCR.bit.SPILBK = 0;  // ��ֹ�Բ���
	SpiaRegs.SPICCR.bit.SPICHAR = 15;  // 16λ����

	SpiaRegs.SPICTL.bit.OVERRUNINTENA = 0;  // ��ֹ��������ж�
	SpiaRegs.SPICTL.bit.CLK_PHASE = 0;  // ����SPIʱ��
	SpiaRegs.SPICTL.bit.MASTER_SLAVE = 1;  // MASTERģʽ
	SpiaRegs.SPICTL.bit.TALK = 1;  // ʹ�ܷ���
	SpiaRegs.SPICTL.bit.SPIINTENA = 0;  // ��ֹ�ж�

	SpiaRegs.SPIBRR = 127;  // ������ = LSPCLK/128 = 293K

	SpiaRegs.SPIFFTX.bit.SPIRST = 1;  // ���¿�ʼFIFO���ͽ���
	SpiaRegs.SPIFFTX.bit.SPIFFENA = 1;  // FIFO��ǿʹ��
	SpiaRegs.SPIFFTX.bit.TXFIFO = 1;  // ����ʹ�ܷ���FIFO����
	SpiaRegs.SPIFFTX.bit.TXFFIENA = 0;  // ��ֹƥ���ж�
	SpiaRegs.SPIFFTX.bit.TXFFIL = 16;  // 16������

	SpiaRegs.SPIFFRX.bit.RXFIFORESET = 1;  // ����ʹ�ܷ���FIFO
	SpiaRegs.SPIFFRX.bit.RXFFIENA = 0;  // ��ֹƥ���ж�
	SpiaRegs.SPIFFRX.bit.RXFFIL = 16;  // 16������

	SpiaRegs.SPIFFCT.bit.TXDLY = 0;  // 0�����ӳ�

	SpiaRegs.SPIPRI.bit.SOFT = 1;  // ����������ֹͣ
	SpiaRegs.SPIPRI.bit.FREE = 0;

	SpiaRegs.SPICCR.bit.SPISWRESET = 1; // ȡ�������λ״̬
}

// ���͵�������
void spiSend(Uint16 a)
{
    SpiaRegs.SPITXBUF=a;
}
