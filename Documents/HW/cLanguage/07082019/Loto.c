#include<stdio.h>
#include<stdlib.h>

void assignArray(char* mat,int size,int chooseNum);
void randNum(char* mat,int size);
void printArray(char* mat,int size);

int main()
{
	char mat[7][7],i,j,size=7;
	for(i=0;i<7;i++)
	{
		for(j=0;j<size;j++)
			{
				mat[i][j]='-';				
			}	
	}
	printArray((char*)mat,size);
	randNum((char*)mat,size);
	
	return 0;
}

void assignArray(char* mat,int size,int chooseNum)
{
	int R,C;
	if(chooseNum>10)
	{
		R=chooseNum/10;
	}
	if(chooseNum<10)
	{
		R=0;
	}

	C=chooseNum%10;
		
	mat[R][C]='+';
}


void randNum(char* mat,int size)
{	
	int i=0, chooseNum,prevNum=0;
	srand(time(NULL));	
	while(i<=5)
	{
		chooseNum = rand() % 50+1;
		if(chooseNum!=prevNum)
		{
			assignArray((char*)mat,size,chooseNum);
			i++;
			prevNum==chooseNum;	
		}
		
		
	}
}


void printArray(char* mat,int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%c\t",mat[i][j]);
		}
	}
}
