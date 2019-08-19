#ifndef packing
#define packing

	struct Packing
	{
		unsigned int m_L :4;
		unsigned int m_R :4;

	};
	typedef struct Packing Packing;



	union Union
	{
		Packing m_pack;
		char m_c;
	};
	typedef union Union Union;

	int pack(char* str);
	int packUnion(char* str,Union packPtr);
#endif
