#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
​
int same_num();
void random_lotto(int *arr,int size);
int randomNum();

​
int main()
{
	int i,size=6;
	int randArr[6];
	srand (time(NULL));
	for(i=0;i<6;i++)
	{
		randArr[i] = randomNum();
		printf("%d\n",randArr[i]);
	}
	random_lotto(randArr,size);
	return 0;
}
​
/*choose 6 random numbers in range of [1,49]*/
int randomNum()
{
	int n1;
	n1 = rand() %49+1;
	return n1;
}
​
​/*creating card of -, and assign + at the random places*/
void random_lotto(int *arr,int size)
{
	char card[5][10];
	int i,j,k=1,r,c;
	for(i=0;i<5;i++)
	{
		for(j=0;j<10;j++)
		{
			card[i][j]='-';
		}
	}
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<size;k++)
			{
				if(arr[k]>10)
				{
					r=arr[k]/10;
				}
				if(arr[k]<10)
				{
					r=0;
				}
				c=arr[k]%10;
				card[r][c]='+';
				
			}
		}
	}
	/* print plus or minus*/
	for(i=0;i<5;i++)
	{
		printf("\n");
		for(j=0;j<10;j++)
		{
			printf("%c\t",card[i][j]);
		}
	}
}
​












