#ifndef
typedef struct text word;
struct text
{
	char** words;
	char* freq;

};

int lengthOfFile(FILE* fp);
void freqLetter(char* str,char* smallChar,char* bigChar);
void readstr();
void printN_lines(int N);
#endif




