#ifndef header
 
typedef struct meet
{
	float begin;
	float end;
	int numRoom;
}Meeting_t;



typedef struct calender
{
	Meeting_t **meetings;
	int capacity;
	int index;
}Calendar_t;



Calendar_t* CreatAD(int capacity);
Meeting_t* CreateMeet();

int insert(Calendar_t,Meeting_t);
int IndexforInsert();
Calendar_t* shift_right(Calendar_t* ptr,int idx);
int removeMeet(Calendar_t,float);
Meeting_t* CreateMeet(Meeting_t* meet)
int printAD(Calendar_t* ptr);
void destroy(Calendar_t* ptr);

void loadFromFile(Calendatr_t* ptr);
Meeting_t* CreateMeetingFile(float beginMeet,float endMeet,int numRoomMeet);
void savePrintf(Calendar_t1*)
i


#endif
