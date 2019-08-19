#include<stdio.h>
#include<string.h>
#include "packing.h"

int main()
{
	char str[]="abcdefg";
	int res_pack=1,opt=10,res_Union=1;
	Union packPtr;

	while(opt)
	{
			printf("Please choose what to do\n");
			printf("1: compress by bitwise operations\n");
			printf("2: compress by union type\n");

			scanf("%d",&opt);

			switch(opt)
			{
				case 1:
				{
					res_pack=pack(str);
					printf("str in length %d\n\n",res_pack);
					break;
				}
				case 2:
				{
					res_Union=packUnion(str,packPtr);
					printf("str in length %d\n\n",res_Union);	
					break;
				}

			}

	}

	
	
	
	return 1;

}

