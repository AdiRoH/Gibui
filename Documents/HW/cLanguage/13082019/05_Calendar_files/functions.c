#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
struct meet
{
	float begin;
	float end;
	int numRoom;
};
struct calender
{
	Meeting_t *meetings;
};
*/



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


Meeting_t* CreateMeet(Meeting_t* meet)
{
	int numRoomMeet;
	float beginMeet,endMeet;

	printf("insert begin time\n");
	scanf("%f",&beginMeet);
	printf("insert end time\n");
	scanf("%f",&endMeet);
	printf("insert number of rooms\n");
	scanf("%d",&numRoomMeet);

	if(endMeet>=beginMeet)
		return NULL;
	meet=malloc(sizeof(meet));
	if(meet==NULL)
		return NULL;
	meet->begin=beginMeet;
	meet->end=endMeet;
	meet->numRoom=numRoomMeet;
	return meet; 
}

int binarySearch(float search,float first,float last)
{
	float middle = (first+last)/2,res;
 
    while (first <= last) 
    {
      if (middle < search)
      {
         first = middle + 1;
      }    
      else if (middle == search) 
      {
         res=1;
         break;
      }
      else
      {
         last = middle - 1;
      }
 
      middle = (first + last)/2;
   }
   if (first > last)
      res=0;
   return res;
}
/*
int Insert(Calendar_t* ptr,int allMeet)
{
	int i=1,insrt_success;
	Meeting_t* currentMeet=CreateMeet();
	while(i<=allMeet)
	{
		if(i==1)
		{
			ptr=CreatAD(ptr,allMeet);
			ptr->meetings[0]=currentMeet;
		}
		else 
		{
			if(ptr->meetings[i].end==currentMeet.begin);
			{
				if(binarSearch(currentMeet.end,ptr->meetings[i].end,ptr->meetings[i+1].begin))
				{
					ptr=CreatAD(ptr,allMeet+1);
					ptr=shift(ptr,i,allMeet);/*allMeet-current size of array, after realocation*/
					/*
					ptr->meetings[i+]=currentMeet;
					insrt_success=1;
				}
				else
				{
					insrt_success=0;
				}

			}
			else if(ptr->meetings[i]->begin==currentMeet->end);
			{
				if(binarSearch(currentMeet.begin,ptr->meetings[i-1].end,ptr->meetings[i].begin))
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

			}
		}
		i++;
	}		
}
*/
int IndexforInsert()
{
}

Calendar_t* shift_right(Calendar_t* ptr,int idx)
{
	int i;
	for(i=idx;i<ptr->capacity-1;i++)
		ptr->meetings[i+1]=ptr->meetings[i];
	return ptr;
}

Calendar_t* shift_left(Calendar_t* ptr,int idx)
{

}

void RemoveMeet();
void SearchgMeet();

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

void LoadFile(char name,char mode)
{
	FILE *fp;
	fp=fopen(name,format);
	if(fp==NULL)
		return NULL;
	else return fp;
}

void SaveFile(FILE* fp,Calendar_t* ptr)
{
	int i;	
	for(i=0;i<ptr->capacity;i++)	
	{
		fprintf("Meeting number #%d,i");
		fprintf(fp,"the begin time: %f,the end time: %f, room #%d",ptr->meetings[i]->begin,ptr->meetings[i]->end,ptr->meetings[i]->numRoom);
	}	
}

int CloseFile(FILE* fp)
{
	int result;
	result=fclose(fp);
	return result;
}
