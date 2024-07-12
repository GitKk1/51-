#include <REGX52.H>
#include "intrins.h"
#include "Delay.h"
#include "Timer0.h"
#include "Seg7.h"


sbit pl1=P1^0;
sbit pl2=P1^1;
sbit pl3=P1^2;
sbit pl4=P1^3;
sbit pl5=P1^4;
sbit pl6=P1^5;
sbit pl7=P1^6;
sbit pl8=P1^7;

int Judge()
{
	unsigned char num;
	switch(P1)
	{
		case 0xfe: num=1; break;
		case 0xfd: num=2; break;
		case 0xfb: num=3; break;
		case 0xf7: num=4; break;
		case 0xef: num=5; break;
		case 0xdf: num=6; break;
		case 0xbd: num=7; break;
		case 0x7f: num=8; break;
	}			
	return num;
}