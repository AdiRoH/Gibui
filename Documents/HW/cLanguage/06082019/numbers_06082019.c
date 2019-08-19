#include<stdio.h>

int reverse(int);
int check_Palindrome(int);
int check_Ascending(int);
int check_perfectNum(int);
int check_primeNum(int);

int main()
{
	int num_palindrome,num_ascending,num_perfect,num_reverse,num_prime;
	int res_palindrome,res_ascending,res_perfect,res_reverse,res_prime;
	/*check Palindrome*/
	printf("Please insert an integer number, to check if it is  palindrome\n");
	scanf("%d",&num_palindrome);
	res_palindrome = check_Palindrome(num_palindrome);
	printf("The answer is %d\n",res_palindrome);
	printf("\n\n");
	
	/*check ascending order*/
	printf("Please insert an integer number, to check if this is an ascending number\n");
	scanf("%d",&num_ascending);	
	res_ascending = check_Ascending(num_ascending);
	printf("The answer is %d\n",res_ascending);
	printf("\n\n");

	/*check perfect number*/
	printf("Please insert an integer number, to check if this is a perfect number\n");
	scanf("%d",&num_perfect);	
	res_perfect = check_perfectNum(num_perfect);
	printf("The answer is %d\n",res_perfect);
	printf("\n\n");

	/*reverse a number*/
	printf("Please insert an integer number, which you want to reverse\n");
	scanf("%d",&num_reverse);	
	res_reverse = reverse(num_reverse);
	printf("The answer is %d\n",res_reverse);
	printf("\n\n");


	/*prime number*/
	printf("Please insert an integer number, to check if this is a prime number\n");
	scanf("%d",&num_prime);	
	res_prime = check_perfectNum(num_prime);
	printf("The answer is %d\n",res_prime);
	printf("\n\n");
	return 0;

}

/*function, which is reverse the digits of the number*/
int reverse(int num)
{
	int number=num,first,newNum=0,invert_num;
	while(number>0)
	{
		first=number%10;
		newNum=newNum*10+first;
		number=number/10;
	}
	return newNum;
}

/*function that check wheather the number is a palindrome*/
int check_Palindrome(num)
{	int ans,invert_num;
	
	invert_num=reverse(num);

	if(invert_num==num)
	{
		ans=1;
	}
	else
	{
		ans=0;
	}
	return ans;		
}

/*function that check wether a number is in ascending order*/
int check_Ascending(int num)
{
	int newNum=0,first,ans=1,number=num,number1=0,second=0;
	while(number>0)
	{
		first=number%10;
		number1=(number-first)/10;
		second=number1%10;
		if(first<second)
		{
			ans=0;
			break;
		}
					
		number=number/10;	
	}
	return ans;
}

/*function that check wether a number is a perfect number*/
int check_perfectNum(int num)
{
	int sum=0,i=1,mult=1,ans;
	while(i<num)
	{
		if(num%i==0)
		{
			sum=sum+i;
			mult=mult*i;
		}

		i++;
	}

	if(sum==mult)
	{
		ans=1;	
	}
	else
	{
		ans=0;
	}
	return ans;
}

/*function that check wether a number is a prime number*/
int check_primeNum(int num)
{
	int res=2,ans=1;
	while(res<num)
	{
		if(num%res==0)
		{
			ans=0;
			break;
		}
		res++;
	}
	return ans;
}


