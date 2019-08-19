#include<stdio.h>
#include<string.h>
#include "packing.h"


int static checkInput(char* str)
{
	char validInput[]={'a','b','c','d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o','\0'};
	int counter=0,i,j; 
	if(str==NULL)
	{
		return 0;
	}
	for(i=0;i<strlen(str);i++)
	{
		counter=0;

		for(j=0;j<strlen(validInput);j++)
		{
			if(str[i]==str[j])
			{
				counter++;
			}
		}
		if(counter==15)
		{
			return 0;
		}
	}
	return 1;
}

void static int2Bin(unsigned int num)
{
	int i=0,j;
	char binNum[256];

	while(num>0)
	{
		binNum[i]=num%2+'0';
		num=num/2;
		i++;
	}

	
	binNum[i]='\0';

	for(i=8;i>=0;i--)
	{
		if(i<=strlen(binNum))
			printf("%c ",binNum[i]);
		else
			printf("%c ",'0');
	}
	return;
}

int printStr(char* str)
{
	int i;
	if(str==NULL)
	{
		return 0;
	}
	for(i=0;i<strlen(str);i++)
		int2Bin((unsigned char)str[i]);
	return 1;
}



int pack(char* str)
{
	int i,res_validInpt,counter=1,len;
	len=strlen(str);
	if(str==NULL)
	{
		return 0;
	}

	res_validInpt=checkInput(str);
	if(res_validInpt==0)
	{
		return 0;
	}	
	
	for(i=0;i<strlen(str)-1;i+=2)
		{
			if(i%2==1)
			{
				str[i]=str[i]-'a';
				str[i-counter]=str[i-counter]|str[i];
				str[i]<<8;

			}
			else
			{
				str[i]-='a';
				str[i-counter]=str[i-counter]|str[i];
				str[i-counter]<<=4;
				str[i]<<=8;
				counter++;
			}
		}
	for(i=0;i<len/2;i++)
	{
		int2Bin((unsigned int)str[i]);	
	}

	return len;
}


int packUnion(char* str,Union packPtr)
{
	
	int i,j,res_validInpt=1,len=strlen(str);

	
	if(str==NULL)
	{
		return 0;
	}
	
	for(i=0;i<strlen(str);i++)
	{
		if(str==NULL)
		{
			return 0;
		}
	}
		
	

	res_validInpt=checkInput(str);
	if(res_validInpt==0)
	{
		return 0;
	}	

	for(i=0,j=1;j<strlen(str);i+=2,j+=2)
	{
		str[i]=str[i]-'a';
		str[j]=str[j]-'a';
		packPtr.m_pack.m_R=str[i];
		packPtr.m_pack.m_L=str[i];
		str[i]=packPtr.m_c;
		
	}
	return len;
}
	
