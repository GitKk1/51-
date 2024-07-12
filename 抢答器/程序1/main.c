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
	unsigned char flag=0;//主持人按下按键标志
	unsigned char num=0;
	buzzer=0;
	Timer_Init();//定时器初始化
	
	while(1)
	{
		if(host==0)//开始抢答
		{
			flag=1;
			TR0 = 1;//启动定时器
			Time=15;//设置抢答时间
			OE_=0;//选手可以按下按键
		}
		
		if(flag==1)
		{
			pl_num_disp(num);//显示选手号码
			Rtime_disp(Time/10,Time%10,num);//显示抢答倒计时
			if(P1!=0xff)//选手开始抢答
			{
				num=Judge();//获取选手号码
				if(num)
				{
					OE_=1;//其他按键不能响应
					Time=30;
				}
			}
			
			if(Time==0)//计时结束
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

void Timer0_Rountine() interrupt 1  //延时一秒
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