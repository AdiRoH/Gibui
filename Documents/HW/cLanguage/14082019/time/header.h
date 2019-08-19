#ifndef header
#define header

	typedef struct c_Date_t c_Date_t;
	typedef struct cTime_t cTime_t;

	struct cTime_t
	{
		unsigned int hour;
		unsigned int min;
		unsigned int sec;
	};


	struct c_Date_t
	{
		unsigned int day;
		unsigned int month;
		unsigned int year;
	};


	int checkInput(unsigned int hour, unsigned int min, unsigned int sec);
	void setTime(cTime_t* timePtr,unsigned int hour,unsigned int min,unsigned int sec);
	void printTime(cTime_t* timePtr,int format);
	c_Date_t* addDate(c_Date_t* datePtr,c_Date_t* datePtr2);	
	unsigned int currHour(cTime_t* timePtr);
	unsigned int currMin(cTime_t* timePtr);
	unsigned int currSec(cTime_t* timePtr);
	cTime_t* addTime(cTime_t* timePtr1, cTime_t* timePtr2);

	int leapYear(unsigned int year);
	int checkInputDate(unsigned year,unsigned int month,unsigned int day);
	cTime_t* alloTime();
	c_Date_t* setDate(c_Date_t* ptrDate,unsigned int day,unsigned int month,unsigned int year);

	int leapYear(c_Date_t* datePtr);
	int checkInputDate(c_Date_t* datePtr);
	c_Date_t* alloDate();
	c_Date_t* setDate(c_Date_t* ptrDate,unsigned int day,unsigned int month,unsigned int year);
	void printDate(c_Date_t* datePtr,int format);
	unsigned int DOY(c_Date_t* datePtr);
	unsigned int currDay(c_Date_t* datePtr);
	unsigned int currMonth(c_Date_t* datePtr);
	unsigned int currYear(c_Date_t* datePtr);
	void nameOfMonth(c_Date_t* datePtr,char* nameFull);

#endif
