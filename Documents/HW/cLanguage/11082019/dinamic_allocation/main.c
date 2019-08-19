#include<stdio.h>
#include<stdlib.h>
#include "dinamicAlocation.h"

int main()
{
	int capacity,res;
	Array_t* array;
	int* num=malloc(sizeof(int));
	*num=99;

	printf("Insert a capcity\n");
	scanf("%d",&capacity);
	array=creatArray(capacity);

	if(array==NULL) 
		return 0;

	while(*num!=-1)
	{
		printf("Insert a number\n");
		scanf("%d",num);
		res=insert(array,num);
		print(array);
		num=malloc(sizeof(int));
		
	}
	destroyDA(array);

	return 0;
}
