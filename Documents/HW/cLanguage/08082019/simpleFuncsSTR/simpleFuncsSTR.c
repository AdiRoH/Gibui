#include<stdio.h>
#include<string.h>

int cmpStr(char *str1,char *str2);
void cpyStr(char *str1,char *str2);
void catStr(char* strDst,char* strSrc);

int main()
{
	/*NOTE: I limited the size of strings, 
	to prevent a situation of the user typing a paragraph inside the string*/
	char str1_cmp[100],str2_cmp[100],str1_cpy[100],str2_cpy[100],str1_cat[100],str2_cat[100];
	int res_cmp;

	/*compare 2 strings*/
	printf("Please insert 2 strings for comparing them\n");
	scanf("%s%s",str1_cmp,str2_cmp);
	res_cmp=cmpStr(str1_cmp,str2_cmp);
	printf("The 2 strings are: %s %s.\n When comparing them:\t%d\n",str1_cmp,str2_cmp,res_cmp);

	/*copy string*/
	printf("Please insert 2 strings for copying the first string to the second string\n");
	scanf("%s%s",str1_cpy,str2_cpy);
	cpyStr(str1_cpy,str2_cpy);
	printf("The new str is:\t%s\n",str2_cpy);

	/*catenation 2 strings*/
	printf("Please insert 2 strings for catenation the second string to the first string\n");
	scanf("%s%s",str1_cat,str2_cat);
	catStr(str1_cat,str2_cat);
	printf("%s\n",str1_cat);
	
	return 0;

}


int cmpStr(char *str1,char *str2)
{
	int i=0;
	while(str1[i]==str2[i]&&str1[i]!='0')
	{
		i++;
	}
	return str1[i]-str2[i];
}

void cpyStr(char *str1,char *str2)
{
	int i,size2=strlen(str2);
	for(i=0;str2[i]<size2;i++)
	{
		str2[i]=str1[i];
	}
	str2[size2]='0';
}

void catStr(char* strDst,char* strSrc)
{
	int i=strlen(strDst),j;
	
	for(j = 0; strSrc[j] != '\0'; ++j, ++i)
    {
        strDst[i] = strSrc[j];
    }
    strDst[i]='\0';
}

