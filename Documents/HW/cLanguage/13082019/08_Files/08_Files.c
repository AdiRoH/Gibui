
#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#include "header"


int lengthOfFile(FILE* fp)
{
	int pos;
	if(fp==NULL)
		return 0;

	fseek(fp,0,2);
	pos=ftell(fp);
	return pos;
}


/*doesn't work...
/*
word* findFreq(word* ptrWord)
{
	
	FILE* fp;
	int num=100,i=0,flength;

	char line[200],singleWord[20];
	if(ptrWord==NULL)
		return NULL;

	fp=fopen("files.txt","r");
	if(fp==NULL)
		return NULL;

	flength=lengthOfFile(fp);

	ptrWord->words = malloc(sizeof(ptrWord->words) * flength);
	
	
	while(!feof(fp))
	{
		fgets(line,num,fp);
		
		{	
			i=0;
			while(i<strlen(line))
			{
				if(line[i]==" "||line[i]==","||line[i]==".")
				{
					ptrWord->words[i]=singleWord;
					/*adding realoc for the new word*//*
					break;
				}
				singleWord[i]=line[i];
				i++;
			}
		}
		
	}

	
	return ptrWord;
}
*/


void freqLetter(char* str,char* smallChar,char* bigChar)
{
	int c=0;

	printf("%s\n",str);
	while(str[c]!="\0")
	{

		if((str[c]>='A')&&(str[c]<='Z'))
		{
			bigChar[str[c]-'A']++;
        }
        else  if((str[c]>='a')&&(str[c]<='z'))
        {
            smallChar[str[c]-'a']++;
        }
		c++;
	}
	printf("%s",smallChar);
}

void readstr()
{
	FILE* fp=fopen("textFile.txt","r");
	int num=600,res,i;
	int count[200];
	char line[200],small[26],capital[26];
	if(fp==NULL) return NULL;
	while(!feof(fp))
	{
		fgets(line,num,fp);
		freqLetter(line,small,capital);
		printf("%s\n%s\n%s",line,small,capital);
	
	}
}


void printN_lines(int N)
{
	int num=100,i,lenFile;
	char line[512];
	int* pos;
	FILE* fp;

	pos=malloc(sizeof(int)*N);
	
	fp=fopen("textFile.txt","r");
	if(fp==NULL)
	{
		return;
	}
	
	if(N<lenFile)
	{
		return;
	}

	while(!feof(fp))
	{
		for(i=0;i<N;i++)
		{
			pos[i%N]=ftell(fp);/*how much bytes since start of the program*/
			fgets(line,num,fp);
		}		
	}

	fseek(fp,pos[i%N],0);/*how much bytes from the end*/
	while(!feof(fp))
	{
        printf("%s\n",line);
        fgets(line,100,fp);
    }
}


