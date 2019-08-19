#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main()
{
	int opt=10,cap;
	int numOfRoom,res_insertMeet=1;
	float begin,end;
	enum opt{createAD=1,createMEET=2,insertMEET=3,removeMEET=4,findMEET=5,destroyMEET=6,printAD=7};
	enum opt menu;

	Diary* diaryPtr;
	Meeting* meetPtr;
	
	while(opt>0)
	{
		printf("Please choose what to do:\n\n");
		printf("1:\tcreate an AD\n\n");
		printf("2:\tcreate a meet\n\n");
		printf("3:\tinsert a meet\n\n");
		printf("4:\tremove a meet\n\n");
		printf("5:\tfind a meet\n\n");
		printf("6:\tdestroy an AD\n\n");
		printf("7:\tprint an AD\n\n");
		
		scanf("%d",&opt);

		switch(opt)
		{
			case createAD:
			{
				printf("insert a capacity\n\n");
				scanf("%d",&cap);
				diaryPtr = createAd(cap);
				diaryPtr->m_cap=1;
				break;
			}
			
			case createMEET:
			{
				
				printf("Please insert number of room\n\n");
				scanf("%d",&numOfRoom);
				printf("Please insert time of begining\n\n");
				scanf("%f",&begin);
				printf("Please insert time of ending\n\n");
				scanf("%f",&end);
				meetPtr=createMeeting(diaryPtr,begin,end,numOfRoom,diaryPtr->m_cap-1);
				break;
			}
			
			case insertMEET:
			{
				
				res_insertMeet = insertMeet(diaryPtr,meetPtr);
				if(res_insertMeet==0)
				{
					printf("Error!\n\n");
				}
				break;
			}
			
			case removeMEET:
			{

			}
		
			case findMEET:
			{
				
			}
		
			case destroyMEET:
			{

			}

			case printAD:
			{
			}
		
		}
	}

	return 1;
}
