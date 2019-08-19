#ifndef header
#define header
	
	struct Meeting
	{
		float m_begin;
		float m_end;
		int m_nOfRoom;
	};
	typedef struct Meeting Meeting;



	struct Diary
	{
		Meeting** m_meet;   /*[meeting 1][meating 2][meeting 3]...*/
		int m_cap;
	}; 
	typedef struct Diary Diary;




	Diary* createAd(int capacity);
	Meeting* createMeeting(Diary* diaryPtr,float begin,float end, int numOfRoom,int index);
	int insertMeet(Diary* diaryPtr,Meeting* meetPtr);
	/*int removeMeet(float begin);
	Meeting* findMeet(float begin);
	void printAd(Diary* diaryPtr);*/
	void destroy(Diary* diaryPtr);
#endif




