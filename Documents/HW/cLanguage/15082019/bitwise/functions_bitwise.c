#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"


Bitmap* createBitmap(int nf)
{
	Bitmap* bitmapPtr=malloc(sizeof(Bitmap));
	if(bitmapPtr==NULL) 
	{
		return NULL;
	}
	
	bitmapPtr->m_features=(char*)calloc(nf,sizeof(char));
	if(bitmapPtr->m_features==NULL) 
	{
		return NULL;
	}
	
	else return bitmapPtr;
}


int bitStatus(Bitmap* bitmapPtr ,int n)
{
	char bit1=1;

	if(bitmapPtr==NULL)
	{
		return -1;
	}

	if(bitmapPtr->m_features==NULL)
	{
		return -1;
	}

	if(n>=bitmapPtr->m_nf||n<0)
	{
		return -1;
	}

	if(bitmapPtr->m_nf<=8)
	{
		return bitmapPtr->m_features[n/8]&(bit1<<(n%8));
	}
	else
	{
		return bitmapPtr->m_features[n/8]&(bit1<<(8-(n%8)));
	}
}

static int printArray(Bitmap* bitmapPtr,int byte)
{
	int i,on;

	if(bitmapPtr==NULL)
	{
		return 0;
	}

	if(bitmapPtr->m_features==NULL)
	{
		return 0;
	}
	
	for(i=bitmapPtr->m_nf-1;i>=0;i--)
	{
		on=bitStatus(bitmapPtr,i);
	
		if(0<on)
		{
			printf("1");
		}
		else if(on==0)
		{
			printf("0");
		}
	}
	printf("\n\n");
	return 1;
}		


int bitOn(Bitmap* bitmapPtr,int n)
{
	int bit,byte,print_res;
	int res_print;
	char bit1=1;
	
	if(bitmapPtr==NULL)
	{
		return 0;
	}

	if(bitmapPtr->m_features==NULL)
	{
		return 0;
	}
	
	bit = bitmapPtr->m_nf-(n%8);
	byte = n/8;
	if(n<=8)
	{
		bitmapPtr->m_features[byte]=(bit1<<=(bit))|bitmapPtr->m_features[byte];
	}
	else
	{
		bitmapPtr->m_features[byte]=(bit1<<=(8-bit)|bitmapPtr->m_features[byte]);
	}
	res_print=printArray(bitmapPtr,byte);	

	return 1;
}

int bitOff(Bitmap* bitmapPtr,int n)
{
	int bit,byte,print_res;
	int res_print;
	char bit1=1;
	
	if(bitmapPtr==NULL)
	{
		return 0;
	}

	if(bitmapPtr->m_features==NULL)
	{
		return 0;
	}
	
	bit = 8-(n%8);
	byte = n/8;

	bitmapPtr->m_features[byte]=(~(bit1<<=(bit)))&bitmapPtr->m_features[byte];
	res_print=printArray(bitmapPtr,byte);	

	return 1;
}

int destroy(Bitmap* bitmapPtr)
{
	if(bitmapPtr==NULL)
	{
		return 0;
	}

	if(bitmapPtr->m_features==NULL)
	{
		return 0;
	}

	free(bitmapPtr->m_features);
	free(bitmapPtr);

	return 1;
}
