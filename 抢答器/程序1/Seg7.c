#include <REGX52.H>
#include "Delay.h"

sbit w1=P2^1;
sbit w2=P2^2;
sbit w3=P2^3;
sbit w4=P2^4;
sbit LED=P3^0;
sbit buzzer=P2^6;

unsigned char test=0;

unsigned char code_table[]={
	0x3F,  //"0"
    0x06,  //"1"
    0x5B,  //"2"
    0x4F,  //"3"
    0x66,  //"4"
    0x6D,  //"5"
    0x7D,  //"6"
    0x07,  //"7"
    0x7F,  //"8"
    0x6F,  //"9"
}; 

void pl_num_disp(unsigned char num)//显示选手号码
{
		w1=0;
		P0=code_table[0];
		Delay(5);
		w1=1;
		w2=0;
		P0=code_table[num];
		Delay(5);
		w2=1;
}

void Rtime_disp(unsigned char s,unsigned char g,unsigned char num)//显示倒计时时间
{
		if(test!=g&&g<6&&s==0&&num==0)
		{
			buzzer=1;
		}
		w3=0;
		P0=code_table[s];
		Delay(5);
		w3=1;
		w4=0;
		P0=code_table[g];
		Delay(5);
		w4=1;
		test=g;
}