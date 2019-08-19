#include<math.h>
#include<stdio.h>
#include"header.h"

int main()
{
	int opt=10,n_rotate;
	unsigned char numInvert,resInvert,numRotate,resRotate,res_setBits,x,y,res_setBitsVal,w;
	unsigned int p,n,i,j,value;
	while(opt>0)
	{
		printf("1: invert a number\n\n");
		printf("2: rotate left\n\n");
		printf("3: setbits\n\n");
		printf("4: setbits\n\n");
		
		scanf("%d",&opt);
		
		switch(opt)
		{
			case 1:
			{
				printf("insert a number to invert\n\n");
				scanf("%hh",&numInvert);
				resInvert = invert(numInvert);
				printf("The inverted number is: %d\n\n",resInvert);
				break;
			}
			case 2:
			{
				printf("Insert a number to rotate\n\n");
				scanf("%hh",&numRotate);
				printf("Insert number of elements for rotation\n\n");
				scanf("%d",&n_rotate);
				resRotate=rotateLeft(numRotate,n_rotate);
				printf("The rotated number is %d",resRotate);
			}
			case 3:
			{
				printf("Insert the main number\n\n");
				scanf("%hh",&x);
				printf("Insert the second number\n\n");
				scanf("%hh",&y);
				printf("insert p\n\n");
				scanf("%u",&p);
				printf("insert n\n\n");
				scanf("%u",&n);
				res_setBits=setbits(x,p,n,y);
				printf("The new number is: %d \n\n",res_setBits);
			}
			case 4:
			{
				printf("Insert number\n\n");
				scanf("%hh",&w);	
				printf("Insert begin of the range\n\n");
				scanf("%u",&i);
				printf("Insert end of the range\n\n");
				scanf("%u",&j);
				printf("Please inseert the value of change- zero or one\n\n");
				scanf("%u",&value);
				res_setBitsVal=setbitsVal(w,i,j,value);
				printf("The new number is: %d ",res_setBitsVal);
			}
		}
	}


}
