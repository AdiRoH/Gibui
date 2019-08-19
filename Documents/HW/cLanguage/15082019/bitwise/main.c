#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"



int main()
{
	int opt=10,numFeatures;
	int nBitOn,res_bitOn,nBitOff,res_bitOff,nBitCheck,res_bitCheck,res_destroy;
	enum opt {On=1,Off=2,CheckStatus=3};
	

	fun_ptr bitOption[3]={bitOn,bitOff,bitStatus};	
	

	Bitmap* arr_features;
	enum opt menu;


	printf("Please insert number of features\n\n");
	scanf("%d",&numFeatures);
	printf("\n\n");
	

	arr_features = createBitmap(numFeatures);
	arr_features->m_nf=numFeatures;

	while(opt>=0)
	{
		printf("Please type what to do\n\n");
		printf("1:\tTurn on bit\n\n");
		printf("2:\tTurn off bit\n\n");
		printf("3:\tCheck status of bit\n\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case On:
			{
				printf("Please choose what bit to turn on. put attation- the bits are counted from left to right\n\n");
				scanf("%d",&nBitOn);
				res_bitOn=bitOption[0](arr_features,nBitOn);
				if(res_bitOn==0)
				{
					printf("Error! try again\n\n");
				}
				break;
			}
			case Off:
			{
				printf("Please choose what bit to turn off. put attation- the bits are counted from left to right\n\n");
				scanf("%d",&nBitOff);
				res_bitOff=bitOption[1](arr_features,nBitOff);
				if(res_bitOn==0)
				{
					printf("Error! try again\n\n");
				}
				break;
			}
			case CheckStatus:
			{
				printf("Please choose what bit to check. put attation- the bits are counted from left to right\n\n");
				scanf("%d",&nBitCheck);
				res_bitCheck=bitOption[2](arr_features,nBitCheck);
				if(res_bitCheck==-1)
				{
					printf("Error! try again\n\n");
				}
				if(res_bitCheck>1)
				{
					printf("Bit %d is in status: 1\n\n",nBitCheck);
				}
				else
				{
					printf("Bit %d is in status: 0\n\n",nBitCheck);
				}
				break;
			}
		}
	}

	res_destroy=destroy(arr_features);
	if(res_destroy==0)
	{
		printf("Error!\n\n");
	}

	return 0;
}
