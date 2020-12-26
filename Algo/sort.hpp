#pragma once
#include <stdio.h>
#define  swap(a, b) (a)^=(b) ; (b)^=(a); (a)^= (b);


//#define SORT_DEBUG
/**
(1)、插入排序：直接插入排序、二分法插入排序、希尔排序。
(2)、选择排序：直接选择排序、堆排序。
(3)、交换排序：冒泡排序、快速排序。
(4)、归并排序
(5)、基数排序

稳定：插入、冒泡、归并
不稳定：选择、快排
 */


/**
 * 输出数据
 */
void SortPrint(int *nArr, int nLen)
{
#ifndef SORT_DEBUG
	return;
#endif
	printf("[");
	for (int i = 0; i < nLen; i++)
	{
		printf("%d ", nArr[i]);
	}
	printf("]\n");
}

/**
 * 插入排序 
 * 时间复杂度：O(n^2)
 */
void SortInsert(int *nArr, int nLen)
{
	for (int i = 1 ; i < nLen; i++)
	{
		for (int j = i; j > 0 && nArr[j] < nArr[j - 1]; j--)
		{
			swap(nArr[j], nArr[j - 1]);
		}
#ifdef SORT_DEBUG
		SortPrint(nArr, nLen);
#endif // SORT_DEBUG
		
	}
}

/**
 * 冒泡排序
 * 时间复杂度：O(n2)
 */
void SortBubble(int *nArr, int nLen)
{
	bool bHasSwap = true;
	for (int i = 1; i < nLen && bHasSwap; i++)
	{
		bHasSwap = false;
		for (int j = 0 ; j < nLen - i ;j++)
		{
			if(nArr[j] > nArr[j + 1])
			{
				swap(nArr[j], nArr[j + 1]);
				bHasSwap = true;
			}
		}
#ifdef SORT_DEBUG
		SortPrint(nArr, nLen);
#endif // SORT_DEBUG
	}
}


/**
 * 归并排序 
 * 时间复杂度：0
 */





/**
 * 选择排序
 * 时间复杂度：O(n2)
 */
void SortSelect(int *nArr, int nLen)
{
	for (int i = 0; i < nLen - 1; i++)
	{
		int index = i;
		for (int j = i + 1; j < nLen; j++)
		{
			if (nArr[index] > nArr[j])
			{
				index = j;
			}
		}
		swap(nArr[i], nArr[index]);
#ifdef SORT_DEBUG
		SortPrint(nArr, nLen);
#endif // SORT_DEBUG
	}
}

/**
 * 快速排序
 * 时间复杂度：O(nlogn)
 */
void SortQuick(int *nArr, int nLen, int r)
{
	while (nLen < r)
	{
		int x = nLen, y = r, z = nArr[(nLen + r) >> 1];
		do {
			while (x >= y && nArr[x] < z) x++;
			while (x >= y && nArr[x] > z) y--;
			if (x <= y)
			{
				swap(nArr[x], nArr[y]);
				x++;
				y--;
			}
		} while (x <= y);
		SortQuick(nArr, x, r);
		r = y;
	}
}

