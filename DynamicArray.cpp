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
int DynamicArraySort(tDynamicArray * ptArr)  //改进版
{
	int i, temp,doneflag,searchmax;
	if (ptArr->dwSize <= 0)
	{
		return FALSE;
	}
	searchmax = ptArr->dwSize;

	//for (j = 0; j < ptArr->dwSize;j++)
	while(searchmax>0)
	{
		doneflag = 0;
		for (i = 0; i <searchmax - 1; i++)
		{
			if (ptArr->pdwA[i] > ptArr->pdwA[i + 1])
			{
				temp = ptArr->pdwA[i];
				ptArr->pdwA[i] = ptArr->pdwA[i + 1];
				ptArr->pdwA[i + 1] = temp;
				doneflag = i + 1;
			}
		}
		searchmax = doneflag;
		//if (doneflag == TRUE)
		//{
		//	break;
		//}
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
int DynamicArrayBinSearch(tDynamicArray * ptArr, int src)  //优化，支持稳定查找，总返回相同内容中秩最大者
{
	int dwmin,dwmid,dwmax,flag;
	if (ptArr->dwSize <= 0)
	{
		return -1;
	}
	
	dwmin = 0;
	dwmax = ptArr->dwSize ;
	flag = 0;
	while (dwmin<dwmax)
	{
		dwmid = (dwmin + dwmax) >>1;
		
		//if (ptArr->pdwA[dwmid] == src)
		//{
		//	res = dwmid;
		//}
		if (ptArr->pdwA[dwmid] > src)
		{
			dwmax = dwmid ;
		}
		else
		{
			if ((ptArr->pdwA[dwmid] == src)&&(flag == 0))
			{
				flag = 1;
			}
			dwmin = dwmid + 1;
			//printf("\r\n		%d", dwmin);
		}
	}
	if (flag==1)
	{
		dwmin = dwmin - 1;
		return dwmin;
	}
	else
	{
		return -1;
	}


}
/************************************************************************/
/* Author   : DingFeng
/* Data     : 2019/05/05
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
static void DynamicArrayMerge(int * ptArrL1,int sizeL1, int * ptArrL2, int sizeL2)
{
	int *temp;
	int i, j,k;

	temp = (int*)malloc(sizeof(int)*sizeL1);

	for (i = 0; i < sizeL1;i++)
	{
		temp[i] = ptArrL1[i];  //复制前向子向量
	}

	i = 0;
	j = 0;
	k = 0;

	while ((i<sizeL1)&&(j<sizeL2))
	{
		if (temp[i]<= ptArrL2[j])
		{
			ptArrL1[k++] = temp[i++];
		}
		else
		{
			ptArrL1[k++] = ptArrL2[j++];
		}
	}

	while (i<sizeL1)
	{
		ptArrL1[k++] = temp[i++];
	}
	while (j<sizeL2)
	{
		ptArrL1[k++] = ptArrL2[j++];
	}

	free(temp);
}

void DynamicArrayMergeSort(int * ptArr, int sizeL)
{
	int *ptArrL1;
	int *ptArrL2;
	int sizeL1;
	int sizeL2;
	if (sizeL>1)
	{
		ptArrL1 = ptArr;
		sizeL1 = sizeL / 2;
		ptArrL2 = ptArr + sizeL1;
		sizeL2 = sizeL - sizeL1;
		DynamicArrayMergeSort(ptArrL1, sizeL1);
		DynamicArrayMergeSort(ptArrL2, sizeL2);

		DynamicArrayMerge(ptArrL1, sizeL1, ptArrL2, sizeL2);
	}

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
//		DynamicArrayInsert(&tDyArr, i, i);//插入
//	}
//	DynamicArrayInsert(&tDyArr, 0, 100);//插入
//	DynamicArrayShow(&tDyArr);
//	DynamicArrayDelet(&tDyArr, 0);//删除
//
//	DynamicArrayPermute(&tDyArr);//置乱
//
//								 //DynamicArraySort(&tDyArr);//排序
//
//	for (i = 100; i < 200; i++)
//	{
//		DynamicArrayInsert(&tDyArr, i, i - 100);//插入
//	}
//
//	//DynamicArraySort(&tDyArr);//排序
//	DynamicArrayMergeSort(tDyArr.pdwA, tDyArr.dwSize);
//	DynamicArrayShow(&tDyArr);
//
//	//DynamicArrayUniquify(&tDyArr);
//
//	//DynamicArrayDeduplicate(&tDyArr);//唯一化
//
//	//DynamicArrayShow(&tDyArr);
//	findidx = DynamicArrayBinSearch(&tDyArr, FINDNUM);
//	printf("\r\n Find %d at %d", FINDNUM, findidx);
//	DynamicArrayDestory(&tDyArr);
//	system("PAUSE");
//	return;
//}