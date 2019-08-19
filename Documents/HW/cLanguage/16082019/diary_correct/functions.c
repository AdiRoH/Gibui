#include<stdio.h>
#include<stdlib.h>
#include "header.h"

Diary* createAd(int capacity)
{
	Diary *diaryPtr= malloc(sizeof(Diary*));
	if(diaryPtr==NULL)
	{
		return NULL;
	}	
	diaryPtr->m_meet=malloc(sizeof(Meeting*)*capacity);
	
	return diaryPtr;
}

Meeting* createMeeting(Diary* diaryPtr,float begin,float end, int numOfRoom,int index)
{
	Meeting* meet;

	if(diaryPtr==NULL)
	{
		return NULL;
	}
	
	meet=malloc(sizeof(diaryPtr->m_meet));
	diaryPtr->m_meet;	
	meet->m_begin=begin;
	meet->m_end=end;
	meet->m_nOfRoom=numOfRoom;
	
	return meet;
}	

int static shiftRight(int insertIDX,Diary* diaryPtr)
{
	int i=0; 

	if(diaryPtr==NULL)
	{
		return 0;
	}
	
	if(diaryPtr->m_meet==NULL)
	{
		return 0;
	}
	

	for(i=insertIDX;i<diaryPtr->m_cap-1;i++)
	{
		diaryPtr->m_meet[i+1]=diaryPtr->m_meet[i];
	}
	
	return 1;
}

int static findIdxOfMeet(float begin,float end,Diary* diaryPtr)
{
	int index,insertIDX=-1,i;
	
	if(diaryPtr == NULL)
	{
		return -1;
	}	
	
	if(diaryPtr->m_meet==NULL)
	{
		return -1;
	}
	
	else if(diaryPtr->m_meet[0]->m_begin>= begin)
	{		
		insertIDX = 0;
	}
	else if(diaryPtr->m_meet[diaryPtr->m_cap-1]->m_end<end)
	{
		insertIDX = diaryPtr->m_cap-1;		
	}
	else
	{
		for(i = 0; i <= diaryPtr->m_cap - 1; i++)
		{
			if(begin >= diaryPtr->m_meet[i]->m_end && end <= diaryPtr->m_meet[i + 1]->m_begin)
			{
				insertIDX = i + 1;
			}
		}
	}
	
	if(insertIDX == -1) /*meetings overlap*/
	{
		printf("Meetings overlap! Please choose another time.\n\n");
		return -1;
	}
	
	return insertIDX;
}

static Diary* reAllo(Diary* diaryPtr)
{
	Diary* temp=diaryPtr;
	diaryPtr->m_meet=(Meeting**)realloc(temp,(diaryPtr->m_cap)*sizeof(Meeting*)*2);
	if(diaryPtr->m_meet==NULL)
	{
		return temp;
	}
	diaryPtr->m_cap=diaryPtr->m_cap+1;
	return diaryPtr;
}

int insertMeet(Diary* diaryPtr, Meeting* meetPtr)
{
	
	int insertIDX,shiftRes;
	
	if(diaryPtr == NULL)
	{
		return 0;
	}	
	
	if(meetPtr==NULL)
	{
		return 0;
	}
	
	insertIDX=findIdxOfMeet(meetPtr->m_begin,meetPtr->m_end,diaryPtr);
	if(insertIDX==-1)
	{
		return 0;
	}
	
	diaryPtr=reAllo(diaryPtr);
	if(diaryPtr==NULL)
	{
		return 0;
	}
	
	shiftRes=shiftRight(insertIDX,diaryPtr);
	if(shiftRes==0)
	{
		return 0;
	}
	
	
	diaryPtr->m_meet[insertIDX]=meetPtr;
	
	
	return 1;
}




void destroy(Diary* diaryPtr)
{
	int i;	
	if((diaryPtr!=NULL)&&(diaryPtr->m_meet!=NULL))
	{
		for(i=0;i<diaryPtr->m_cap;i++)
		{
			free(diaryPtr->m_meet[i]);
		}

		free(diaryPtr);
	}
}
