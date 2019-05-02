#ifndef _DYNAMICARRAY_H_ //如果没有引入头文件file.h
#define _DYNAMICARRAY_H_ //那就引入头文件file.h

#define TRUE	1
#define FALSE	0
#define  DEBUG_

typedef struct tDynamicArray
{
	int *pdwA;
	int dwSize;
	int dwCapacity;
}tDynamicArray;

extern int DynamicArrayInit(tDynamicArray * ptArr,int dwCapacity);
extern int DynamicArrayPut(tDynamicArray * ptArr,int r,int data);
extern int DynamicArrayGet(tDynamicArray * ptArr,int r);
extern int DynamicArrayShow(tDynamicArray * ptArr);
extern int DynamicArrayInsert(tDynamicArray * ptArr, int r, int data);
extern int DynamicArrayDelet(tDynamicArray * ptArr, int r);
extern int DynamicArrayDestory(tDynamicArray * ptArr);
extern void test(void);

#endif
