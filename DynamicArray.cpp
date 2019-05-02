#include <iostream>
#include "stdio.h"
#include<stdlib.h>
#include"DynamicArray.h"

/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/03
/* Fuction	: 
/* Remarks	:
/* Others	:
/************************************************************************/
static int DynamicArrayExpand(tDynamicArray * ptArr)
{
	int* p;
	int i;

	p = (int *)malloc(ptArr ->dwCapacity * 2 * sizeof(int));
	if (p == NULL)
	{
#ifdef DEBUG_
		printf("\r\nExpand Fail! %4d", ptArr->dwCapacity);
#endif
		return FALSE;
	}

	for (i = 0; i < ptArr->dwCapacity;i++)
	{
		p[i] = ptArr->pdwA[i];
	}
	free(ptArr->pdwA); //Free the old space

	ptArr->dwCapacity *= 2;
	ptArr->pdwA = p;
#ifdef DEBUG_
	printf("\r\nExpand! %4d", ptArr->dwCapacity);
#endif
	return TRUE;
}




/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/03
/* Fuction	: 
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArrayInit(tDynamicArray * ptArr, int dwCapacity)
{
	ptArr->dwCapacity = dwCapacity;
	ptArr->dwSize = 0;
	ptArr->pdwA = (int *)malloc(dwCapacity * sizeof(int));
	if (ptArr->pdwA != NULL)
	{
		return TRUE;
	}

	return FALSE;
}


/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/03
/* Fuction	: 
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArrayPut(tDynamicArray * ptArr, int r, int data)
{

	if ((r >= ptArr->dwSize))
	{
		return FALSE;
	}

	ptArr->pdwA[r] = data;
	return TRUE;
}


/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/03
/* Fuction	: 
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArrayGet(tDynamicArray * ptArr, int r)
{
	if ((r >= ptArr->dwSize))
	{
		return FALSE;
	}

	return ptArr->pdwA[r];
}


/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/03
/* Fuction	: 
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArrayInsert(tDynamicArray * ptArr, int r, int data)
{
	int i;
	if ((r<0) || (r > ptArr->dwSize))
	{
		return FALSE;
	}

	if (ptArr->dwSize >=ptArr->dwCapacity)
	{
		DynamicArrayExpand(ptArr); //need expand
	}

	for (i = ptArr->dwSize; i > r;i--)
	{
		ptArr->pdwA[i] = ptArr->pdwA[i - 1];
	}
	ptArr->pdwA[r] = data;
	ptArr->dwSize++;
	return TRUE;
}


/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/03
/* Fuction	: 
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArrayDelet(tDynamicArray * ptArr, int r)
{
	int i;
	if ((r<0) || (r >= ptArr->dwSize))
	{
		return FALSE;
	}

	for (i = r; i < ptArr->dwSize - 1;i++)
	{
		ptArr->pdwA[i] = ptArr->pdwA[i + 1];
	}
	ptArr->dwSize--;
	return TRUE;
}


/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/03
/* Fuction	: 
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArrayShow(tDynamicArray * ptArr)
{
	int i;
	if ((ptArr->pdwA ==NULL)||(ptArr->dwSize == 0))
	{
#ifdef DEBUG_
		printf("\r\nEmpty! %4d %4d",ptArr->dwSize , ptArr->dwCapacity);
#endif
		return FALSE;
	}
	printf("\r\n****** Array Show ******");
	printf("\r\n* size=%4d  ca=%4d *", ptArr->dwSize, ptArr->dwCapacity);
	for (i = 0; i < ptArr->dwSize;i++)
	{
		printf("\r\n %4d %4d",i, DynamicArrayGet(ptArr,i));
	}
	printf("\r\n****** End ******");
	return TRUE;
}


/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/03
/* Fuction	: 
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArrayDestory(tDynamicArray * ptArr)
{
	free(ptArr->pdwA);
	return TRUE;
}
/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/03
/* Fuction	: 
/* Remarks	:
/* Others	:
/************************************************************************/
//void main(void)
//{
//	int i;
//	cout << "\r\n hello world" << endl;
//	tDynamicArray tDyArr;
//	DynamicArrayInit(&tDyArr, 10);
//	for (i = 0; i < 1000; i++)
//	{
//		DynamicArrayInsert(&tDyArr, i, i);
//	}
//	DynamicArrayInsert(&tDyArr, 0, 100);
//	DynamicArrayShow(&tDyArr);
//	DynamicArrayDelet(&tDyArr, 0);
//	for (i = 0; i < 1000; i++)
//	{
//		DynamicArrayPut(&tDyArr, i, 999 - i);
//	}
//	DynamicArrayShow(&tDyArr);
//
//	DynamicArrayDestory(&tDyArr);
//	system("PAUSE");
//	return;
//}