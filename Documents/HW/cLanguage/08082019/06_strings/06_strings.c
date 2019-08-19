#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Int2Bin(char* binNum,int num);
int Bin2Int(char* binNum);
int power(int base, int exp);/*couldn't compile with pow() of math.h*/
void reverseArr(char* str);
int Location(char* str1,char* str2);
void squeeze(char* str1,char* str2);



int main()
{
	int choose=1,option,i,decNum1,binNum2,decNum2,res_Location;
	char binSTR2[]="\0";
	char binNum1[]="\0",str1_Location[]="\0",str2_Location[]="\0",str1_squeeze[]="\0",str2_squeeze[]="\0";

	while(choose)
	{	
		printf("Please choose option\n\n");
		printf("\t1:\tConvert a decimal number(positive integer number)\n\n");
		printf("\t2:\tConvert a binari number to a decimal number\n\n");
		printf("\t3:\tSqueeze:delete each character in s1 that matches any character in the s2\n\n");
		printf("\t4:\tFind location of string s1 in sub-string s2\n\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1: /*convert dec to bin*/
			{
				printf("Please insert a positive integer number\n");
				scanf("%d",&decNum1);
				Int2Bin(binNum1,decNum1);
				
				reverseArr(binNum1);
				for(i=0;i<strlen(binNum1);i++)
				{
					printf("%c",binNum1[i]);
				}
				printf("\n\n");


				int i=0;
				for(i=0;i<strlen(binNum1);i++)
				{
				    binNum1[i] = 0;
				}
				binNum1[strlen(binNum1)]="\0";
				
				break;
			}
			case 2: /*convert bin to dec*/
			{
				printf("Please insert a binari number of positive integer\n");
				scanf("%d",&binNum2);
				sprintf(binSTR2,"%d",binNum2);
				decNum2=Bin2Int(binSTR2);
				printf("%d",decNum2);
				printf("\n\n");
				decNum2=0;
				break;
			}
			case 3: /*squeeze*/
			{
				printf("Please insert a string\n");
				scanf("%s",str1_squeeze);
				printf("\nPlease insert a string\n");
				scanf("%s",str2_squeeze);
				squeeze(str1_squeeze,str2_squeeze);
				printf("\n%s",str1_squeeze);
				printf("\n\n");
				break;
			}
			case 4: /*Location*/
			{
				printf("Please insert the long string\n");
				scanf("%s",str1_Location);
				printf("\nPlease insert the sub string\n");
				scanf("%s",str2_Location);
				res_Location=Location(str1_Location,str2_Location);
				printf("%d\n",res_Location);
				printf("\n\n");
				break;
			}
			default:
				return -1;
		}
	}
	return 0;
}

void Int2Bin(char* binNum,int num)
{
	int i=0;
	while(num>0)
	{
		binNum[i]=num%2+48;
		num=num/2;
		i++;
	}
}

void reverseArr(char* str)
{ 
	int i,j,length=strlen(str),temp;
	int middle=1+(length-1)/2;
	for(i=0,j=length-1;i<=middle;i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
}

void initialize(char* str)
{


}

int Bin2Int(char* binNum)
{
	int decDigit,decNum, binNum_digit,iteration;
	int binNum_int=atoi(binNum),size=0;
	while(binNum_int>0)
	{
		binNum_digit=binNum_int%10;
		if(binNum_digit==1)
		{
			iteration=binNum_digit*power(2,size);
			decNum+=iteration;
		}
		
		size++;
		binNum_int/=10;
	}
	return decNum;
}

int power(int base, int exp)
{
	int res=1,i=1;
	if(exp==0)
		res=1;
	else
	{
		while(i<=exp)
		{
			res=res*base;
			i++;
		}
	}
	return res;
}


int Location(char* str1,char* str2)
{
	int i,flag=0,idx,j,location=-1;
	
	/*check that the user insert the sub-string as the second string*/
	if(strlen(str2)>strlen(str1))
	{
			printf("you inserted the sub string which is longer than the string itself");
			printf("Please insert the strings again\n");
			return -1;
	}
	
	for(i=0;i<strlen(str1);i++)
	{
		printf("flag:%d\n",flag);
		if(str2[0]==str1[i])
		{
			flag=1;
			location=i;
			break;
		}
	}
	
	
	
	if(flag==1)
	{
		for(idx=1;idx<strlen(str2);idx++)
		{
			for(j=i;j<i+strlen(str1)-1;j++)
			{	
				if(str2[idx]!=str1[j])
				{
					printf("II");
					flag=0;
					break;
				}
			}
		}
	}
	
	if(flag=0)
	{
		location=-1;
	}
	return location;
}


void squeeze(char* str1,char* str2)
{
	int i,j,k;
	int size1=strlen(str1);
	for(i=0;i<size1;i++)
	{
		for(j=0;j<strlen(str2);j++)
		{
			if(str1[i]==str2[j])
			{
				k=i+1;
				while(k<size1)
				{
					str1[k-1]=str1[k];
					k++;

				}
				size1--;
				str1[size1]="\0";

			}
		}	
	} 
}








