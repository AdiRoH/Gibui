#include<stdio.h>
void func1(n1){
	int i,j;
	for(i=1; i<=n1; ++i) //print the triangle
	{
        	for(j=1; j<=i; ++j){
           		 printf("*");
        	}
        	printf("\n");
    	}
}

void func2(n2){
	
	int i,j;
	for(i=1; i<=n2; ++i) //print the upper triangle
	{ 
        	for(j=1; j<=i; ++j){
           		 printf("*");
        	}
        	printf("\n");
    	}


	for(i=1;i<n2;i++) //print the lower triangle
	{ 
		for(j=i;j<n2;j++){
			printf("*");	
		}
	printf("\n");
	}
}

void func3(n3){
	int i,j, k=0,space;
	for (i = 1; i <= n3*4; i++) //Loop to print rows 
	{
		for (j = 1; j < n3; j++){//Loop to print spaces in a row
			printf(" ");
		}
		n3--;
	
		for (j = 1; j <= 2*i - 1; j++){// Loop to print stars in a row
			printf("*");
		}
		printf("\n");
  	}
}

int main(){
	int num;
	//inserting a number
	printf("Please insert a number\n");
	scanf("%d",&num);
	
	//calling the functions
	func1(num);
	printf("\n\n");

	func2(num);
	printf("\n\n");
	
	func3(num);
	
	return 0;
}
