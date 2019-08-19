#include<stdio.h>

void printArray(int* arr,int size);
void swap(int* a,int* b);
void bubbleSort(int* arr,int size);
void countZero(int* arr,int size);
void sortEvenOdd(int* arr,int size);
int occurTheMost(int* arr, int size);



int main()
{
	int arr1[]={1,5,5,4,3,6,2,0,9},arr2[]={1,0,1,0,0,0,1,1,1},arr3[]={1,5,5,4,3,6,2,0,9},arr4[]={1,5,5,4,3,6,2,0,9};
	int size=9;
	int res;
	
	/*ascending order*/
	/*doesn't work well.I write the algorithm which was spoken in the class*/
	printArray(arr1,size);
	bubbleSort(arr1,size);
	printf("\nThe ascending array is:\n");
	printArray(arr1,size);
	printf("\n\n");

	/*sorting binary array*/
	printArray(arr2,size);
	countZero(arr2,size);
	printf("\nThe sorted array is:\n");
	printArray(arr2,size);
	printf("\n\n");
	
	/*sorting even-odd*/
	/*doesn't work perfectly. not sure why*/
	printArray(arr3,size);
	sortEvenOdd(arr3,size);
	printf("\nThe sorted even-odd array is:\n");
	printArray(arr3,size);
	printf("\n\n");

	/*occur the most*/
	/*i'm not sure wether sorting this array ar first,in ascending order, is more eficient.*/
	printArray(arr4,size);
	res=occurTheMost(arr4,size);
	printf("\nThe most repeated (and first) element of the array is:\n%d",res);

	return 0;
}

/*general function to print an array*/
void printArray(int* arr,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
}

/*function to sort a binary array*/
void countZero(int* arr,int size)
{
	int i,counter=0;	
	for(i=0;i<size;i++)
	{
		if(arr[i]==0)
		{
			counter++;		
		}
	}
	for(i=0;i<counter-1;i++)
	{
		arr[i]=0;
	}
	for(i=counter;i<size;i++)
	{
		arr[i]=1;
	}
}

/*swap function*/
void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

/*smart bubble sort*/
void bubbleSort(int *arr,int size)
{
	int i=0,j,sizeCheck=size,counter=0;;
	while(i<sizeCheck)
		{
			for(j=1;j<size;j++)
			{
				if(arr[j-1]>arr[j])
				{
					swap(&arr[j-1],&arr[j]);
					counter++;
				}		
			}

			if(counter==0)
				{
					break;
				}

			i++;
			sizeCheck=sizeCheck-1;
		}
}


/*sort array by even-odd numbers*/
void sortEvenOdd(int* arr,int size)
{
	int i,j,temp,counter=0;
	for(i=1;i<size;i++)
	{
		if(arr[i]%2==0)
		{
			temp=arr[counter];
			arr[counter]=arr[i];
			for(j=i-1;j>counter;j--)
			{
				arr[j+1]=arr[j];
			}
			counter++;
			arr[counter]==temp;		
		}
	}
}

/*find out the most repeated element in the array*/
int occurTheMost(int* arr, int size)
{
	int i,j,val,elementcounter=1,max=0,mostOccur=arr[0],counter=1;	
	for(i=0;i<size;i++)
	{
		counter=1;

		for(j=0;j<size;j++)
		{
			if(arr[j]==arr[i]&&arr[j]!=-1)
			{
				arr[j]==-1;
				counter++;
			}

			if(max<counter)
			{
				max=counter;
				mostOccur=arr[i];
			}
		
		}
	}
	return mostOccur;
}
