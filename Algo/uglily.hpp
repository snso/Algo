#pragma once
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <VzTimeUtils.h>

int Min(int x, int y, int z)
{
	int tmp = (x < y) ? x : y;
	return (tmp < z) ? tmp : z;
}

int GetNum(int index)
{
	if (index <= 0)
		return 0;

	int *pUglyNumbers = new int[index]();
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while (nextUglyIndex < index)
	{
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;//��ǰ����
		std::cout << min << std::endl;
		while (*pMultiply2 * 2 <= min)	//���ݱ�����õĳ���������´�Ҫ��ĳ�����pMultiply2 ��λ��
			++pMultiply2;
		while (*pMultiply3 * 3 <= min)
			++pMultiply3;
		while (*pMultiply5 * 5 <= min)
			++pMultiply5;
		++nextUglyIndex;
	}
	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;

}

int uglily()
{
	int n;
	std::cin >> n;
	CVzTimeUtils timeUtils;
	timeUtils.Update();
	std::cout << GetNum(n) << std::endl;
	std::cout << timeUtils.GetElapsedTimeInMilliSec();
	return 0;
}

