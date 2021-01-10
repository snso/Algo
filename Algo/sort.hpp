#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SORT_DEBUG
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
#if 0
		printf("%d-%d ", i, nArr[i]);
#else
		printf("%d ", nArr[i]);
#endif
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
			std::swap(nArr[j], nArr[j - 1]);
		}
		SortPrint(nArr, nLen);
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
				std::swap(nArr[j], nArr[j + 1]);
				bHasSwap = true;
			}
		}
		SortPrint(nArr, nLen);
	}
}

/**
 * 归并排序 
 * 时间复杂度：0
 */

void SortMerge(int *nArr, int nStart, int nEnd)
{
	//分到最小后进行比较
	if (nEnd - nStart <= 1)
	{
		if (nEnd - nStart == 1 && nArr[nEnd] < nArr[nStart])
		{
			std::swap(nArr[nEnd], nArr[nStart]);
		}
		return;
	}
	//数据进行分割
	int nMid = (nStart + nEnd) >> 1;
	SortMerge(nArr, nStart, nMid);
	SortMerge(nArr, nMid + 1, nEnd);

	//分割完进行合并
 	int* pTmp = new int[nEnd - nStart + 1];
	int nBegin = nStart, nCen = nMid + 1;
	int nIndex = 0;
	while (nBegin <= nMid || nCen <= nEnd)
	{
		if (nCen > nEnd || (nBegin <= nMid && nArr[nBegin] < nArr[nCen]))
		{
			pTmp[nIndex++] = nArr[nBegin++];
		}
		else
		{
			pTmp[nIndex++] = nArr[nCen++];
		}
	}
	memcpy(nArr + nStart, pTmp, sizeof(int) * (nEnd - nStart + 1));
	delete[] pTmp;
	SortPrint(nArr + nStart, nEnd - nStart);
}


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
		std::swap(nArr[i], nArr[index]);
		SortPrint(nArr, nLen);
	}
}

/**
 * 快速排序
 * 时间复杂度：O(nlogn)
 */
void SortQuick(int *nArr, int l, int r)
{
	while (l < r)
	{
		int x = l, y = r, z = nArr[(l + r) >> 1];
		do {
			while (x <= y && nArr[x] < z) x++;
			while (x <= y && nArr[y] > z) y--;
			if (x <= y)
			{
				std::swap(nArr[x], nArr[y]);
				x++;
				y--;
			}
		} while (x <= y);
		SortQuick(nArr, x, r);
		r = y;
	}
}

