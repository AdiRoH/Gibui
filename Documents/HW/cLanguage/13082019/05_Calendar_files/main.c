#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
	int opt,numOfMeet,allMeet=0,res;
	Calendar_t* diaryPTR=malloc(sizeof(Calendar_t));
	Meeting_t* meetPTR=malloc(sizeof(Meeting_t));
	if(diaryPTR==NULL)
		return -1;
	if(meetPTR==NULL)
		return -1;
	
	while(1)
	{
		printf("Please choose option. to exit type 2\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
					printf("Please insert number of meetings\n");
					scanf("%d",&diaryPTR->capacity);

					diaryPTR=CreatAD(diaryPTR);
					if(diaryPTR!=NULL)
						printf("A diary was create");
					break;
			case 2:
					printf("insert information of meeting");
					meetPTR=CreateMeet(meetPTR);
					break;
			case 3:
					/*for(i=1;i<=numOfMeet;i++)
						insert meeting;
					allMeet=allMeet+numOfMeet;*/
					
					/*diaryPTR->meetings=meetPTR;*/
					
					break;
				
			case 6:
					destroy(diaryPTR);
					break;
			case 7:
					res=printAD(diaryPTR);
					break;
			default: 
				return -1;
		}
		
	}
	return 0;
}
