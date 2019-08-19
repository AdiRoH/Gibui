#include<stdlib.h>
#include<stdio.h>

int* insert(int num,int* arr, int* index,int* sizeArr);

int main()
{
	int idx=0,num=0,size;
	int *arr,*sizeArr=&size;

	printf("Please insert size of array\n");
	scanf("%d",&size);

	arr=malloc((size)*sizeof(int));
	
	while(num!=-1)
	{
		printf("Please insert a number. To stop-type -1\n");
		scanf("%d",&num);
		insert(num,arr,&idx,sizeArr);
		if(arr[idx]==-1)
		{
			break;
		}
		
	}
	
	free(arr);	
	return 0;	
}


/*num=value of elemnt in the array
arr=array
index=index of the new element in the array
sizeArr=current size of the array*/
	
int* insert(int num,int* arr, int* index,int* sizeArr)
{
	int *address=arr;
	if(*index<*sizeArr)
	{	
		arr[*(index)]=num;
		*(index)++;
	}
	if((*index)==(*sizeArr))
	{
		arr=(int*)realloc(arr,((*sizeArr)*2)*sizeof(int));
		if(arr!=NULL)
		{
			printf("\nnot enough memory to re-allocate\n");
			arr=address;
			(*sizeArr)*=2;
		}
		else
		{
			return arr;
		}
	
		arr[*(index)]=num;
		(*index)++;
	}
	return arr;
}

