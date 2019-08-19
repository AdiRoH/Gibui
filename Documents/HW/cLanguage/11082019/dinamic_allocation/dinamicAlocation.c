#include<stdio.h>
#include<stdlib.h>
#include "dinamicAlocation.h"

Array_t* creatArray(int capacity)
{
	Array_t* array;
	array=malloc(sizeof(Array_t));
	if(array==NULL)
	{
		return NULL;
	}
	array->arr=malloc(capacity*sizeof(int*));
	if(array==NULL)	
	{
		return NULL;
	}
	array->capacity=capacity;
	array->index=0;
	return array;
}


int insert(Array_t* ptr,int* Num)
{	
	int **address=ptr->arr;
	if(ptr==NULL|| Num==NULL) return -1;	
	if((ptr->index)<(ptr->capacity))
	{	
		ptr->arr[ptr->index]=Num;
		ptr->index+=1;
	}
	else 
	{
		ptr->arr=(int**)realloc(ptr->arr,(ptr->capacity*2)*sizeof(int*));
		if(ptr->arr==NULL)
		{
			ptr->arr=address;
			return -1;
		}
		else
		{
			ptr->arr[ptr->index]=Num;
			ptr->capacity+=1;
			ptr->index+=1;
				
		}
	}	
	return 1;
}

void print(Array_t *ptr)
{
	int i;
	/*check null*/	
	for(i=0;i<ptr->index;i++)	
		printf("%d ",*(ptr->arr[i]));
}

void destroyDA(Array_t *ptr)
{
	int i;
	if(ptr!=NULL)
	{
		for(i=0;i<ptr->index;i++)
		{
			free(ptr->arr[i]);
			
		}
		free(ptr);
		
	}	
	
}
