#include<math.h>
#include"header.h"


unsigned char invert(unsigned char num)
{
	return num^255;
}

unsigned int rotateLeft(unsigned char num,int n)
{
	unsigned int num1=num;
	return (num1>>n)|(num<<n);
}

unsigned char setbits(unsigned char x,unsigned int p,unsigned int n,unsigned char y)
{
	unsigned char result1,result2,result3;
	result1 = (pow(2,y));	
	result1 = y%(result1)<<(p-y);
	result2 =x/(pow(2,y));	
	result2 = (result2)<<p;
	result3 = (pow(2,(p-y)));
	result3 = x%(result3);
	return result1|result2|result3;	
}

unsigned char setbitsVal(unsigned char w,unsigned int i,unsigned int j,unsigned int value)
{
	int idx, res;
	for(idx=0;idx<=(j-i);j++)
	{
			res=res*261;
	}

	res<<=j;
	
	if(value==0)
	{
		res=~res;
		w=w&res;

	}
	else
	{
		w=w|res;
	}
	
	return w;
}
