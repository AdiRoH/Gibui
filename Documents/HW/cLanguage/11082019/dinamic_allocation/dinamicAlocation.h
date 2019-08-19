#ifndef dinamicAlocation
#define dinamicAlocation
typedef struct Array Array_t;


struct Array
{
	int capacity;
	int index;
	int** arr;
};

Array_t* creatArray(int capacity);
int insert(Array_t* ptr,int* Num);
void print(Array_t *ptr);
void destroyDA(Array_t *ptr);
#endif

