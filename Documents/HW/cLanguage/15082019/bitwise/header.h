#ifndef header
#define header

	struct Bitmap
	{
		int m_nf;/*multiplication 0f sizeof(char), length of array*/
		char* m_features;/*arr in length of nf-representing the bits of the number*/
	};

	typedef struct Bitmap Bitmap;

	typedef int(*fun_ptr)(Bitmap*,int);

	Bitmap* createBitmap(int m_nf);
	int bitOn(Bitmap* bitmapPtr,int n);
	int bitOff(Bitmap* bitmapPtr,int n);
	int bitStatus(Bitmap* bitmapPtr ,int n);
	int destroy(Bitmap* bitmapPtr);
#endif



