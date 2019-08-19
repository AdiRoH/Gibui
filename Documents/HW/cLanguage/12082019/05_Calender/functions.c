#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"


Calendar_t* CreatAD(Calendar_t* ptr)
{
	Meeting_t** temp;
	if(ptr==NULL) 
	{
		return NULL;
	}
	
	temp=(Meeting_t**)realloc(ptr->meetings,(ptr->capacity*2)*sizeof(Meeting_t*));
	if(temp==NULL) 
	{
		return NULL;
	}
	
	ptr->meetings=temp;

	

	return ptr;	
}


Meeting_t* CreateMeetingFile(float beginMeet,float endMeet,int numRoomMeet)


	Meeting_t* meet=malloc(sizeof(Meeting_t*));
	if(endMeet>=beginMeet)
		return NULL;
	if(meet==NULL)
		return NULL;
	meet->begin=beginMeet;
	meet->end=endMeet;
	meet->numRoom=numRoomMeet;
	return meet; 
}


int Insert(Calendar_t* ptr,Meeting_t* currentMeet)
{
	int i=1,insrt_success;
	while(i<=ptr->capacity)
	{
		if(i==1)
		{
			ptr=CreatAD(ptr);
			ptr->meetings[0]=currentMeet;
		}

		else 
		{
			if(ptr->meetings[i]->end==currentMeet->begin);
			{
				if(binarySearch(currentMeet->end,ptr->meetings[i]->end,ptr->meetings[i+1]->begin))
				{
					ptr->capacity=ptr->capacity+1;
					ptr=CreatAD(ptr);
					ptr=shift_right(ptr,i);/*allMeet-current size of array, after realocation*/
					ptr->meetings[i+1]=currentMeet;
					insrt_success=1;
				}
			}/*
				else
				{
					insrt_success=0;
				}

			}
			else if(ptr->meetings[i]->begin==currentMeet->end);
			{
				if(binarySearch(currentMeet.begin,ptr->meetings[i-1].end,ptr->meetings[i].begin))
				{
					ptr=CreatAD(ptr,allMeet+1);
					ptr=shift(ptr,i,allMeet);/*allMeet-current size of array, after realocation*//*
					ptr->meetings[i-1]=currentMeet;
					insrt_success=1
				else
				{
					insrt_success=0;
				}
			}
			else if(binarSearch(currentMeet.end,ptr->meetings[i].end,ptr->meetings[i+1].begin))
			{

			}*/
		}
		i++;
	}		
}

int IndexforInsert()
{
	int i;
}

Calendar_t* shift_right(Calendar_t* ptr,int idx)
{
	int i;
	for(i=idx;i<ptr->capacity-1;i++)
		ptr->meetings[i+1]=ptr->meetings[i];
	return ptr;
}
/*
Calendar_t* shift_left(Calendar_t* ptr,int idx)
{

}

void RemoveMeet()
{

}

void SearchgMeet()
{

}
*/
int printAD(Calendar_t* ptr)
{
	int i,j;
	if(ptr==NULL)
		return 0;
	for(i=0;i<ptr->capacity;i++)
	{
		printf("Meeting number %d occur at ",i);
		for(j=0;j<=2;j++)
		{
			if(j==2)
			{
				printf("The meeting occut at room #%d\n",ptr->meetings[j]->numRoom);
			}
			else
			{
				printf("%f : %f\n",ptr->meetings[j]->begin,ptr->meetings[j]->end);
			}
		}
	}
	return 1;
}

void destroy(Calendar_t* ptr)
{
	int i;
	if(ptr!=NULL)
	{
		for(i=0;i<ptr->capacity;i++)
			free(ptr->meetings[i]);
		free(ptr);
	}
}

void loadFromFile(Calendatr_t* ptr)
{
	float begin,end;
	int NumOfRoom;
	Meeting_t* meet=malloc()
}
