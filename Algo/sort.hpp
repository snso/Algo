#pragma once
#include <stdio.h>
#define  swap(a, b) (a)^=(b) ; (b)^=(a); (a)^= (b);


//#define SORT_DEBUG
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
		printf("%d ", nArr[i]);
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
			swap(nArr[j], nArr[j - 1]);
		}
#ifdef SORT_DEBUG
		SortPrint(nArr, nLen);
#endif // SORT_DEBUG
		
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
 * �鲢���� 
 * ʱ�临�Ӷȣ�0
 */





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
		swap(nArr[i], nArr[index]);
#ifdef SORT_DEBUG
		SortPrint(nArr, nLen);
#endif // SORT_DEBUG
	}
}

/**
 * ��������
 * ʱ�临�Ӷȣ�O(nlogn)
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

