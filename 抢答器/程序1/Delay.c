#include <REGX52.H>

void Delay(unsigned int x)		//@12.000MHz
{
	unsigned char i, j;
	while(x--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}
