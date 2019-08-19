#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct c_Date_t c_Date_t;

struct c_Date_t
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};


char monthFull[12][128]={"January","February","March","April","May","June","July","August","September","October","November","December"};	

int leapYear(c_Date_t* datePtr)
{
	int res; 
	if(datePtr->year%4==0) return 1;
	else return 0;
}

int checkInput(c_Date_t* datePtr)
{
	int month[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	int res=1,i;
	if(datePtr==NULL) return 0;
	
	if(datePtr->month>12)
		res=0;
		
	for(i=0;i<12;i++)
		if(!leapYear(datePtr)&&datePtr->day>28)
		{
				res=0;
		}
		if(i%2==1&&datePtr->day==31)
		{
			res=0;
		}
		return res;
}


c_Date_t* alloTime()
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


int main()
{
	int opt=1,opt_format,opt_retrieve,isLeap,validIO;
	unsigned int day,month,year,curDay,curMonth,curYear,doy;
	c_Date_t* datePtr=alloTime();
	char nameOfMon[10];
	
	while(opt>0)
	{
		printf("\nPlease choose option. To exit type -1\n\n");
		printf("1:change date of exisiting object\n\n");
		printf("2:print date in a specific format\n\n");
		printf("3:retrieve from object day/month/year\n\n");
		printf("4:adding days together\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				{
					printf("Please insert a day in digits\n");
					scanf("%u",&day);
					printf("Please insert a month in digits\n");
					scanf("%u",&month);
					printf("Please insert a year in digits\n");
					scanf("%u",&year);
					
					validIO = checkInput(datePtr);
					if(validIO==0)
					{
						printf("input not valid. please type again\n");
						break;
					}
					else datePtr = setDate(datePtr,day,month,year);
					
					break;
				}
			case 2:
				{
					printf("Please choose format:\n");
					printf("1: regular format\n");
					printf("2: European format\n");
					printf("3: American format\n");
					
					scanf("%d",&opt_format);
					printDate(datePtr,opt_format);
					break;
				}
			case 3:
				{
					printf("Please choose what to retrieve\n");
					printf("1: currrent day in month\n");
					printf("2: current month\n");
					printf("3: current year\n");
					printf("4: day of year\n");
					printf("5: is year leap or no(return 1 if it does)\n");
					printf("6: name of month\n");
					
					scanf("%d",&opt_retrieve);
					
					switch(opt_retrieve)
					{
						case 1:
						{
						 	curDay = currDay(datePtr);
						 	printf("current day in month-%u",curDay);
						 	break;
						 }
					case 2:
						{
							curMonth = currMonth(datePtr);
							printf("current month-%u",curMonth);
							break;
						}
					case 3:
						{
							curYear = currYear(datePtr);
							printf("current year-%u",curYear);
							break;
						}
					case 4:
						{
							doy=DOY(datePtr);
							printf("current year-%u",doy);
							break;
						}
					case 5:
						{
							isLeap=leapYear(datePtr);
							printf("is year leap or not:%d",isLeap);
							break;
						}
					case 6:
						{
							nameOfMonth(datePtr,nameOfMon);
							break;	
						}
					}
					break;
				}
			case 4:
				{
					break;
				}
		}
	}
	return 0;
}
