#include<stdio.h>
#include<stdlib.h>

typedef struct cTime_t cTime_t;

struct cTime_t
{
	unsigned int hour;
	unsigned int min;
	unsigned int sec;
};

int checkInput(unsigned int hour, unsigned int min, unsigned int sec)
{
	int res=1;
	if(hour>24)
		res=0;
	if(min>60)
		res=0;
	if(sec>60)
		res=0;
	return res;
}

cTime_t* alloTime()
{
	cTime_t* timePtr=malloc(sizeof(cTime_t));
	return timePtr;
}

void setTime(cTime_t* timePtr,unsigned int hour,unsigned int min,unsigned int sec)
{
	if(timePtr!=NULL)
	{
		timePtr->hour=hour;
		timePtr->min=min;
		timePtr->sec=sec;
	}

}

void printTime(cTime_t* timePtr,int format)
{
	unsigned int hour;
	char meridiem[2]="MM";

	
	if(timePtr!=NULL)
	{
		if(format==1)
		{
			printf("%u:%u:%u\n",timePtr->hour,timePtr->min,timePtr->sec);
		}
		else if(format==2)
		{
			if(timePtr->hour==24)
			{
				hour=0;
				meridiem[0]='A';
			}
			else if(timePtr->hour>12)
			{
				hour=timePtr->hour-12;
				meridiem[0]='P';
			}
			else 
			{
				hour=timePtr->hour;
				meridiem[0]='A';
			}
			printf("%u:%u:%u %s\n",hour,timePtr->min,timePtr->sec,meridiem);	
		}
	}
}

unsigned int currHour(cTime_t* timePtr)
{
	unsigned int currHour;
	if(timePtr==NULL) return 0;
	currHour=timePtr->hour;
	return currHour;
}
unsigned int currMin(cTime_t* timePtr)
{
	unsigned int currMin;
	if(timePtr==NULL) return 0;
	currMin=timePtr->min;
	return currMin;
}
unsigned int currSec(cTime_t* timePtr)
{
	unsigned int currSec;
	if(timePtr==NULL) return 0;
	currSec=timePtr->sec;
	return currSec;
}

cTime_t* addTime(cTime_t* timePtr1, cTime_t* timePtr2)
{
	unsigned int Hour=0,Min=0,Sec=0,day=0;
	
	if(timePtr1==NULL) return NULL;
	if(timePtr2==NULL) return NULL;
  
    Sec = timePtr1->sec + timePtr2->sec;
    if(Sec>60)
    {
        Min = Sec/60;
        Sec = Sec%60;
    }
    
    Min = Min + timePtr1->min + timePtr2->min;
    
    if(Min>60)
    {
        Hour=Min/60;
        Min=Min%60;
    }
    
    Hour = Hour + timePtr1->hour + timePtr2->hour;
    
    if(Hour>24)
    {
         day=1;
         Hour=Hour%24;
    }

    timePtr1->hour=Hour;
    timePtr1->min=Min;
    timePtr1->sec=Sec;
 	
 	return timePtr1; 
}

int main()
{
	int opt=1,timeValid,timeValid2,formatPrint,formatRetrieve;
	unsigned int hour,min,sec,currH,currM,currS,hour2,min2,sec2;
	cTime_t* timePtr;
	cTime_t* timePtr2;

	timePtr=alloTime();

	while(opt>0)
	{
		printf("Please choose an option from the menu\n\n");
		printf("1:\tset a new time\n\n");
		printf("2:\tprint time in a specific format\n\n");
		printf("3:\tretrieve hours/minutes/seconds\n\n");
		printf("4:\tadd time\n\n");

		scanf("%d",&opt);

		switch(opt)
		{
			case 1:
			{
				
				printf("Please inser hours in digits\n\n");
				scanf("%u",&hour);
				printf("Please inser minutes in digits\n\n");
				scanf("%u",&min);
				printf("Please inser seconds in digits\n\n");
				scanf("%u",&sec);
				timeValid=checkInput(timePtr->hour,timePtr->min,timePtr->sec);
				if(timeValid==0)
					printf("You insert invalid characters. Please typ again\n\n");
				else 
					setTime(timePtr,hour,min,sec);
				break;
			}
			case 2:
			{
				printf("Please choose the format of the printing:\n\n");
				printf("1:\tprint hour in range of [0,24]\n\n");
				printf("2:\tprint hour in range of [0,12]\n\n");
				scanf("%d",&formatPrint);
				printTime(timePtr,formatPrint);
				break;
			}
			case 3:
			{
				printf("Please choose what to retrieve\n\n");
				printf("1:\thours\n\n");
				printf("2:\tminutes\n\n");
				printf("3:\tseconds\n\n");
				scanf("%d",&formatRetrieve);
				switch(formatRetrieve)
				{
					case 1:
						currH=currHour(timePtr);
						printf("The current hour is:%u\n\n",currH);
						break;
					case 2:
						currM=currMin(timePtr);
						printf("The current minute is:%u\n\n",currM);
						break;
					case 3:
						currS=currSec(timePtr);
						printf("The current second is:%u\n\n",currS);
						break;
				}
				break;
			}
			case 4:
			{
				timePtr2=alloTime();

				printf("Please inser hours in digits,which you wants to add\n\n");
				scanf("%u",&hour2);
				printf("Please inser minutes in digits,which you wants to add\n\n");
				scanf("%u",&min2);
				printf("Please inser seconds in digits,which you wants to add\n\n");
				scanf("%u",&sec2);

				timeValid2=checkInput(hour2,min2,sec2);
				if(timeValid2==0)
					printf("You insert invalid characters. Please typ again\n\n");
				else 
				{
					setTime(timePtr2,hour2,min2,sec2);
					timePtr=addTime(timePtr,timePtr2);
					printTime(timePtr,1);
				}


			}
		}
	}
	return 0;
}
