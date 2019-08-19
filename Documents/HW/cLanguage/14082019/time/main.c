#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "header.h"


int main()
{
	int opt=1,opt_format,opt_retrieve_Date,isLeap,validIO,validIO2;
	int timeValid,timeValid2,formatPrint,formatRetrieve;

	unsigned int day,month,year,curDay,curMonth,curYear,doy,day2,month2,year2;
	unsigned int hour,min,sec,currH,currM,currS,hour2,min2,sec2;

	char nameOfMon[10];
	c_Date_t* datePtr=alloDate();
	c_Date_t* datePtr2=alloDate();

	cTime_t* timePtr=alloTime();
	cTime_t* timePtr2=alloTime();

	
	
	
	while(opt>0)
	{
		printf("\nPlease choose option. To exit type -1\n\n");
		printf("1:\tchange date of exisiting object\n\n");
		printf("2:\tprint date in a specific format\n\n");
		printf("3:\tretrieve from object day/month/year\n\n");
		printf("4:\tadding days together\n\n");
		printf("5:\tset a new time\n\n");
		printf("6:\tprint time in a specific format\n\n");
		printf("7:\tretrieve hours/minutes/seconds\n\n");
		printf("8:\tadd time\n\n");

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
					
					validIO = checkInputDate(year,month,day);
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
					
					scanf("%d",&opt_retrieve_Date);
					
					switch(opt_retrieve_Date)
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
							isLeap=leapYear(datePtr->year);
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
					printf("Please insert a day in digits,which you wants to add\n\n");
					scanf("%u",&day2);
					printf("Please insert a month in digits,which you wants to add\n\n");
					scanf("%u",&month2);
					printf("Please insert a year in digits,which you wants to add\n\n");
					scanf("%u",&year2);
					
					validIO2 = checkInputDate(year,month,day);
					if(validIO2==0)
					{
						printf("input not valid. please type again\n");
						break;
					}
					else datePtr2 = setDate(datePtr2,day2,month2,year2);
					
					addDate(datePtr,datePtr2);
					printDate(datePtr,1);
					break;
				}
			case 5:
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
						break;
				}
			case 6:
				{
					printf("Please choose the format of the printing:\n\n");
					printf("1:\tprint hour in range of [0,24]\n\n");
					printf("2:\tprint hour in range of [0,12]\n\n");
					scanf("%d",&formatPrint);
					printTime(timePtr,formatPrint);
					break;
					break;
				}
			case 7:
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
			case 8:
				{	
					printf("Please insert hours in digits,which you wants to add\n\n");
					scanf("%u",&hour2);
					printf("Please insert minutes in digits,which you wants to add\n\n");
					scanf("%u",&min2);
					printf("Please insert seconds in digits,which you wants to add\n\n");
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
					break;
				}
		}
		


		
			

	}
	if(datePtr!=NULL) free(datePtr);
	if(timePtr!=NULL) free(timePtr);
	if(timePtr2!=NULL) free(timePtr2);
	
	return 0;
}
