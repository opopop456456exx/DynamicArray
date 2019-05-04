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
	if (ptArr->pdwA != NULL)
	{
		free(ptArr->pdwA);
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
int DynamicArrayPermute(tDynamicArray * ptArr)
{
	int i,temp,tempidx;
	if (ptArr->dwSize <=0)
	{
		return FALSE;
	}
	for (i = ptArr->dwSize; i > 0;i--)
	{
		tempidx = rand() % i;
		temp = ptArr->pdwA[tempidx];
		ptArr->pdwA[tempidx] = ptArr->pdwA[i - 1];
		ptArr->pdwA[i - 1] = temp;
	}
	return TRUE;
}




/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/03
/* Fuction	: 
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArraySort(tDynamicArray * ptArr)
{
	int i,j, temp,doneflag;
	if (ptArr->dwSize <= 0)
	{
		return FALSE;
	}

	for (j = 0; j < ptArr->dwSize ;j++)
	{
		doneflag = TRUE;
		for (i = 0; i <ptArr->dwSize - 1; i++)
		{
			if (ptArr->pdwA[i] > ptArr->pdwA[i + 1])
			{
				temp = ptArr->pdwA[i];
				ptArr->pdwA[i] = ptArr->pdwA[i + 1];
				ptArr->pdwA[i + 1] = temp;
				doneflag = FALSE;
			}
		}
		if (doneflag == TRUE)
		{
			break;
		}
	}
	return TRUE;
}



/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/04
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArrayFind(tDynamicArray * ptArr, int src)
{
	int i;
	if (ptArr->dwSize <= 0)
	{
		return -1;
	}
	for (i = ptArr->dwSize - 1; i >= 0;i--)
	{
		if (src == ptArr->pdwA[i])
		{
			return i;
		}
	}

	return -1;
}


/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/04
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArrayDeduplicate(tDynamicArray * ptArr)
{
	int i,j;
	if (ptArr->dwSize <= 0)
	{
		return FALSE;
	}
	for ( j = 0; j < ptArr->dwSize; j++)
	{
		for (i = 0; i < j; i++)
		{
			if (ptArr->pdwA[j] == ptArr->pdwA[i])
			{
				DynamicArrayDelet(ptArr,  j);
			}
		}
	}
	return TRUE;
}


/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/04
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArrayUniquify(tDynamicArray * ptArr)
{
	int i, j;
	if (ptArr->dwSize <= 1)
	{
		return FALSE;
	}
	i = 0;
	j = 1;
	while (j<ptArr->dwSize)
	{
		if (ptArr->pdwA[i] != ptArr->pdwA[j])
		{
			i++;
			ptArr->pdwA[i] = ptArr->pdwA[j];
		}
		j++;
	}
	ptArr->dwSize = ++i;
	return TRUE;
}


/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/04
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
int DynamicArrayBinSearch(tDynamicArray * ptArr, int src)
{
	int dwmin,dwmid,dwmax;
	if (ptArr->dwSize <= 0)
	{
		return -1;
	}
	dwmin = 0;
	dwmax = ptArr->dwSize ;

	while (dwmin<dwmax)
	{
		dwmid = (dwmin + dwmax) >>1;
		//printf("\r\n		%d", dwmid);
		if (ptArr->pdwA[dwmid] == src)
		{
			return dwmid;
		}
		else if (ptArr->pdwA[dwmid] > src)
		{
			dwmax = dwmid -1;
		}
		else
		{
			dwmin = dwmid + 1;
		}
	}

	return -1;

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
//	int i, findidx;
//	cout << "\r\n hello world" << endl;
//	tDynamicArray tDyArr;
//	DynamicArrayInit(&tDyArr, 10);
//	for (i = 0; i < 100; i++)
//	{
//		DynamicArrayInsert(&tDyArr, i, i);//²åÈë
//	}
//	DynamicArrayInsert(&tDyArr, 0, 100);//²åÈë
//	DynamicArrayShow(&tDyArr);
//	DynamicArrayDelet(&tDyArr, 0);//É¾³ý
//
//	DynamicArrayPermute(&tDyArr);//ÖÃÂÒ
//
//								 //DynamicArraySort(&tDyArr);//ÅÅÐò
//
//	for (i = 100; i < 200; i++)
//	{
//		DynamicArrayInsert(&tDyArr, i, i - 100);//²åÈë
//	}
//
//	DynamicArraySort(&tDyArr);//ÅÅÐò
//
//	DynamicArrayShow(&tDyArr);
//
//	DynamicArrayUniquify(&tDyArr);
//
//	//DynamicArrayDeduplicate(&tDyArr);//Î¨Ò»»¯
//
//	DynamicArrayShow(&tDyArr);
//	findidx = DynamicArrayBinSearch(&tDyArr, FINDNUM);
//	printf("\r\n Find %d at %d", FINDNUM, findidx);
//	DynamicArrayDestory(&tDyArr);
//	system("PAUSE");
//	return;
//}
