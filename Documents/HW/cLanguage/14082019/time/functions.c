#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "header.h"

static int daysInM [12]={31,28,31,30,31,30,31,31,30,31,30,31};
static char monthFull[12][128]={"January","February","March","April","May","June","July","August","September","October","November","December"};	


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

c_Date_t* addDate(c_Date_t* datePtr,c_Date_t* datePtr2)
{
	unsigned int dayF,monthF;
	dayF=(datePtr->day+datePtr->day)>daysInM[(datePtr->month)-1]?1:0;
	monthF=(datePtr->month+dayF)/12;
	datePtr->day=(datePtr->day+datePtr2->day)%(daysInM[(datePtr->month)-1]);
	datePtr->month=(datePtr->month+dayF)%12;
	datePtr->year=(datePtr->year+monthF);
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
    unsigned int Hour,Min,Sec,day;
	
    Hour=0;
    Min=0;
    Sec=0;
    day=0;
  
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


int leapYear(unsigned int year)
{
	int res; 
	if(year%4==0) return 1;
	else return 0;
}

int checkInputDate(unsigned year,unsigned int month,unsigned int day)
{
	/*int Month[12]={1,2,3,4,5,6,7,8,9,10,11,12};*/
	int res=1,i;
	
	if(month>12)
		res=0;
		
	for(i=0;i<12;i++)
		if(!leapYear(datePtr)>day>28)
		{
				res=0;
		}
		if(i%2==1&&day==31)
		{
			res=0;
		}

	if(day>daysInM[day-1])
		{
			res=0;
		}
		return res;
}



c_Date_t* alloDate()
{
	c_Date_t* ptrDate=malloc(sizeof(c_Date_t));
	return ptrDate;
}

c_Date_t* setDate(c_Date_t* ptrDate,unsigned int day,unsigned int month,unsigned int year)
{
	if(ptrDate==NULL)
	{
		return NULL;
	}
	ptrDate->day=day;
	ptrDate->month=month;
	ptrDate->year=year;
	return ptrDate;
}

void printDate(c_Date_t* datePtr,int format)
{
	char days[9][2]={"01","02","03","04","05","06","07","08","09"};
	char month[12][2]={"01","02","03","04","05","06","07","08","09","10","11","12"};
	
	if(datePtr!=NULL)
	{
		if(format==1&&datePtr->day<=9)
	{
	
		printf("dd:%u,\tmon:%u,\tyear:%u - %s/%s/%u\n",2,2,4,days[datePtr->day-1],monthFull[datePtr->month-1],datePtr->year);
	}
	else if(format==1&&datePtr->day>10)
	{
		printf("dd:%u,\tmon:%u,\tyear:%u - %s/%u/%u\n",2,2,4,days[datePtr->day-1],datePtr->month,datePtr->year);
	}
	
	if(datePtr->day<=9)
	{	
		if(format==2&&datePtr->month<=9)
		{
			printf("dd:%u,\tmon:%u,\tyear:%u - %s/%s/%u\n",2,2,4,days[datePtr->day-1],month[datePtr->month-1],datePtr->year);
		}
		else if(format==3&&datePtr->month<=9)
		{
			printf("mon:%u,\tdd:%u,\tyear:%u - %s/%u/%s",2,2,4,days[datePtr->day-1],datePtr->year,month[datePtr->month-1]);
		}
		else if(format==2&&datePtr->month>9)
			printf("dd:%u,\tmon:%u,\tyear:%u - %u/%s/%u\n",2,2,4,datePtr->day,month[datePtr->month-1],datePtr->year);
		else if(format==3&&datePtr->month>9)
			printf("mon:%u,\tdd:%u,\tyear:%u - %u/%u/%s",2,2,4,datePtr->day,datePtr->year,month[datePtr->month-1]);
	
	}  
	}
	
}



unsigned int DOY(c_Date_t* datePtr)
{

	unsigned int doy = datePtr->day;
	int res,days_in_feb=0;
	res=leapYear(datePtr);
	if(res==1)
		days_in_feb=28;
	switch(datePtr->month)
    {
        case 2:
            doy +=days_in_feb;
            break;
        case 3:
            doy += 31+days_in_feb;
            break;
        case 4:
            doy += 30+days_in_feb+31;
            break;
        case 5:
            doy += 31+days_in_feb+31+30;
            break;
        case 6:
            doy += 30+days_in_feb+31+30+31;
            break;
        case 7:
            doy += 31+days_in_feb+31+30+31+30;
            break;            
        case 8:
            doy += 30+days_in_feb+31+30+31+30+31;
            break;
        case 9:
            doy += 31+days_in_feb+31+30+31+30+31+31;
            break;
        case 10:
            doy += 30+days_in_feb+31+30+31+30+31+31+30;            
            break;            
        case 11:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31;            
            break;                        
        case 12:
            doy += 30+days_in_feb+31+30+31+30+31+31+30+31+30;            
            break;                                    
    }
    return doy;
}

unsigned int currDay(c_Date_t* datePtr)
{
	if(datePtr==NULL) return 0;
	return datePtr->day;
}
unsigned int currMonth(c_Date_t* datePtr)
{
	if(datePtr==NULL) return 0;
	return datePtr->month;
}
unsigned int currYear(c_Date_t* datePtr)
{
	if(datePtr==NULL) return 0;
	return datePtr->year;
}

void nameOfMonth(c_Date_t* datePtr,char* nameFull)
{
	nameFull=monthFull[datePtr->month-1];
}


