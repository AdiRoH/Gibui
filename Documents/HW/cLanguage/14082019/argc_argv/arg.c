#include<stdio.h>
#include<ctype.h>
#include<string.h>

int checkInput(int argc);
int isDigit(char* arg);
int isStr(char* arg);

int main(int argc,char* argv[])
{
	int validInput,arg1_flag=0,arg2_flag=0;	
	
	validInput=checkInput(argc);
	if( validInput && isStr(argv[1])==1 && isDigit(argv[2])==1 )
	printf("%s %s",argv[1],argv[2]);
	else if( argc==3 && isStr(argv[2])==1 && isDigit(argv[1])==1 )
	printf("%s %s",argv[2],argv[1]);
	else
	printf("Error! Please type again input\n");
	return 0;
}	

int checkInput(int argc)
{
	int res=1;
	if(argc!=3)
	{
		printf("Please insert only your name and your age\n");
		res=0;
	}
	return res;

}

int isDigit(char* argv)
{
	int i,arg_flag;
	for(i=0;i<strlen(argv);i++)
	{
		if(!isdigit(argv[i]))
		{
			arg_flag=0;
			break;
		}
	}
	return arg_flag;
}

int isStr(char* argv)
{
	int i,arg_flag=1;
	for(i=0;i<strlen(argv);i++)
		if(!isalpha(argv[i]))
		{
			arg_flag=0;
			break;
		}
	}

	return arg_flag;
}
