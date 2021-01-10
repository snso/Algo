#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SORT_DEBUG
/**
(1)����������ֱ�Ӳ������򡢶��ַ���������ϣ������
(2)��ѡ������ֱ��ѡ�����򡢶�����
(3)����������ð�����򡢿�������
(4)���鲢����
(5)����������

�ȶ������롢ð�ݡ��鲢
���ȶ���ѡ�񡢿���
 */


/**
 * �������
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
 * �������� 
 * ʱ�临�Ӷȣ�O(n^2)
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
 * ð������
 * ʱ�临�Ӷȣ�O(n2)
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
 * �鲢���� 
 * ʱ�临�Ӷȣ�0
 */

void SortMerge(int *nArr, int nStart, int nEnd)
{
	//�ֵ���С����бȽ�
	if (nEnd - nStart <= 1)
	{
		if (nEnd - nStart == 1 && nArr[nEnd] < nArr[nStart])
		{
			std::swap(nArr[nEnd], nArr[nStart]);
		}
		return;
	}
	//���ݽ��зָ�
	int nMid = (nStart + nEnd) >> 1;
	SortMerge(nArr, nStart, nMid);
	SortMerge(nArr, nMid + 1, nEnd);

	//�ָ�����кϲ�
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
 * ѡ������
 * ʱ�临�Ӷȣ�O(n2)
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
 * ��������
 * ʱ�临�Ӷȣ�O(nlogn)
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

