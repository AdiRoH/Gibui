LengthFile()
{
	FILE *fp;
	int num=100,i,N;/*general number...*/
	int* lenLine;
	char* nameOfFile;
	char** str;
	
	printf("Please insert name of file\n");
	scanf("%s",nameOfFile);	
	printf("Please insert number of lines\n");
	scanf("%d",&N)
	
	array=malloc(sizeof(*int)*N);
	fp=fopen(nameOfFile,"r");
	
	while(!feof(fp))
	{
		for(i=0;i<N;i++)
			fgets (*str[i],num,fp);		
	}	
}

/*
FILE* lengthFile()
struct word
{
	char **word;
	int *freq;
}

//read file and calculate num of words
//
array in size N
*/
