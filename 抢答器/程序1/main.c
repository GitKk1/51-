#include <REGX52.H>
#include "intrins.h"
#include "Delay.h"
#include "Timer0.h"
#include "Seg7.h"
#include "PlJudge.h"

sbit host=P2^5;
sbit OE_=P2^0;
sbit buzzer=P2^6;

unsigned char Time;

void main()
{	
	unsigned char flag=0;//�����˰��°�����־
	unsigned char num=0;
	buzzer=0;
	Timer_Init();//��ʱ����ʼ��
	
	while(1)
	{
		if(host==0)//��ʼ����
		{
			flag=1;
			TR0 = 1;//������ʱ��
			Time=15;//��������ʱ��
			OE_=0;//ѡ�ֿ��԰��°���
		}
		
		if(flag==1)
		{
			pl_num_disp(num);//��ʾѡ�ֺ���
			Rtime_disp(Time/10,Time%10,num);//��ʾ���𵹼�ʱ
			if(P1!=0xff)//ѡ�ֿ�ʼ����
			{
				num=Judge();//��ȡѡ�ֺ���
				if(num)
				{
					OE_=1;//��������������Ӧ
					Time=30;
				}
			}
			
			if(Time==0)//��ʱ����
			{
				flag=0;
				TR0 = 0;	
				Time=0;
				num=0;
				buzzer=0;
			}
		}
	}
}

void Timer0_Rountine() interrupt 1  //��ʱһ��
{
	static unsigned int T0count;
	TH0=0xFC;
	TL0=0x18;
	TF0 = 0;
	T0count++;
	if(T0count==500)
	{
		buzzer=0;
	}

	if(T0count>=1000)
	{
		Time--;
		T0count=0;	
	}

}