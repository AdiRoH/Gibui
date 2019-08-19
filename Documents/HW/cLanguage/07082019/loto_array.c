#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void assignArray(char* arr,int chooseNum);
void randNum(char* arr,int size);
void printArray(char* arr,int R, int C);

int main()
{
	char arr[49],i,size=49,r=5,c=10;
	for(i=0;i<size;i++)
	{	
		arr[i]='-';				
				
	}
	printArray(arr,c,r);
	randNum(arr,size);
	
	return 0;
}

void assignArray(char* arr,int chooseNum)
{
	arr[chooseNum]='+';
}


void randNum(char* arr,int size)
{	
	int i=0, chooseNum,prevNum=-1,counter=0;
	srand(time(NULL));	
	while(1)
	{
		chooseNum = rand() % 50+1;
		if(chooseNum!=prevNum)
		{
			assignArray(arr,chooseNum);
			i++;
			prevNum==chooseNum;	
		}
		counter++;
		if(counter==5)
		{
			break;
		}
		
		
	}
}


void printArray(char* arr,int R, int C)
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("%c\t",arr[j]);
		}
		printf("\n");

	}
}

