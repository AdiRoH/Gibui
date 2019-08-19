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
}Calendar_t;



Calendar_t* CreatAD(Calendar_t* ptr);/*capacity=how much are ALL the meetings*/
Meeting_t* CreateMeet(Meeting_t* meet);
int binarySearch(float search,float first,float last);
int Insert(Calendar_t* ptr,int allMeet);
int IndexforInsert();
Calendar_t* shift_right(Calendar_t* ptr,int idx);
Calendar_t* shift_left(Calendar_t* ptr,int idx);
void RemoveMeet();
void SearchgMeet();
int printAD(Calendar_t* ptr);
void destroy(Calendar_t* ptr);
void LoadFile(char name,char mode);
void SaveFile(FILE* fp,Calendar_t* ptr);
int CloseFile(FILE* fp);

#endif
