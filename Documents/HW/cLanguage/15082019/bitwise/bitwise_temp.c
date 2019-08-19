#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct m_bitmap
{
	int nf;/*multiplication 0f sizeof(char), length of array*/
	char* arr;/*arr in length of nf-representing the bits of the number*/
};

typedef struct m_bitmap m_bitmap;

static m_bitmap* createBitmap(int nf);
static void zeroing(char *Arr,int sizeArr);
static void Int2Bin(char* binNum,int num);
int bitOn(m_bitmap* bitmapPtr,int n);
int bitoff(m_bitmap* bitmapPtr,int n);
static int destroy(m_bitmap* bitmapPtr);




/*int isbit();*/



static m_bitmap* createBitmap(int nf)
{
	m_bitmap* bitmapPtr=malloc(sizeof(m_bitmap));
	if(bitmapPtr==NULL) return NULL;
	bitmapPtr->arr=malloc(sizeof(int)*nf);
	if(bitmapPtr->arr==NULL) return NULL;
	else return bitmapPtr;
}


static int destroy(m_bitmap* bitmapPtr)
{
	if(bitmapPtr==NULL)
		return 0;
	if(bitmapPtr==NULL)
		return 0;
	free(bitmapPtr->arr);
	free(bitmapPtr);
	return 1;
}

static void zeroing(char *Arr,int sizeArr)
{
	int i; 	
	for(i=0;i<sizeArr;i++)
		Arr[i]=0;
}

static void Int2Bin(char* binNum,int num)
{
	int i=0;
	while(num>0)
	{
		binNum[i]=num%2+48;
		num=num/2;
		i++;
	}
}

int bitOn(m_bitmap* bitmapPtr,int n)
{
	char bit=1;
	int bitOn,byte;

	if(bitmapPtr==NULL)
	{
		return 0;
	}

	bitOn=n%(sizeof(char)*8);	
	byte=bitmapPtr->arr[n/sizeof(char)+1];

	
	byte=(bit<<=bitOn)&byte;
	printf("%d",byte);
	bitmapPtr->arr[n/sizeof(char)]=byte;
	
	return 1;
}

int bitoff(m_bitmap* bitmapPtr,int n)
{
	char bit='1';
	int bitOff,byte;

	if(bitmapPtr==NULL)
	{
		return 0;
	}

	bitOff=n%sizeof(char);	
	byte=bitmapPtr->arr[n/sizeof(char)];

	byte=((~(bit<<=bitOff))|byte);
	bitmapPtr->arr[n/sizeof(char)]=byte;

	return 1;
}

int main()
{
	int sizeChar,sizeFeatures,numOfBit,bitO,res;
	m_bitmap* bitmapPtr;
	char* bin="\0";
	
	sizeChar=sizeof(char)*8;
	
	
	

	printf("Please insert number of Features\n\n");
	scanf("%d",&sizeFeatures);
	
	bitmapPtr = createBitmap(sizeFeatures/8);
	bitmapPtr->nf=sizeFeatures/8;
	zeroing(bitmapPtr->arr,bitmapPtr->nf);
	
	
	printf("Please insert index of bit in renage of [1,%d], wich you want to turn on\n\n",sizeChar);
	scanf("%d",&numOfBit);
	
	/*bitoff(bitmapPtr,numOfBit);*/
	
	res=bitOn(bitmapPtr,numOfBit);
	bitO=(int)(bitmapPtr->arr[sizeFeatures/8]);
	printf("%d",bitO);
	Int2Bin(bin,bitO);
	printf("%s\n",bin);
	return 1;
}
