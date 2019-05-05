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
extern int DynamicArrayInsert(tDynamicArray * ptArr, int r, int data);// O(n)
extern int DynamicArrayDelet(tDynamicArray * ptArr, int r); //O(n)
extern int DynamicArrayDestory(tDynamicArray * ptArr);

extern int DynamicArrayPermute(tDynamicArray * ptArr);//置乱 O(n)
extern int DynamicArraySort(tDynamicArray * ptArr);//排序 冒泡 O(n2)
extern void DynamicArrayMergeSort(int * ptArr, int sizeL);//并归排序  O(nlogn)  空间O(n)

extern int DynamicArrayFind(tDynamicArray * ptArr,int src);//查找 O(n)
extern int DynamicArrayDeduplicate(tDynamicArray * ptArr);//唯一化 O(n2)
extern int DynamicArrayUniquify(tDynamicArray * ptArr);//唯一化 必须排序后使用 O(n)

extern int DynamicArrayBinSearch(tDynamicArray * ptArr, int src);//二分查找  必须排序后使用 O(log(n))
extern void test(void);

#endif
