#pragma once
#include <iostream>

void Pramesift(unsigned int nMax)
{
	int nArrLen = nMax + 1;
	int* pArr = new int[nArrLen];
	memset(pArr, 0 , sizeof(int) * nArrLen);
	for (int i = 2; i < nArrLen; i++)
	{
		if(pArr[i]) continue;
		pArr[++pArr[0]] = i;	//记录质数
		for (unsigned int j = i * 2; j < nArrLen; j += i)
		{
			pArr[j] = 1; //标记合数
		}
	}
#if 0
	for (int i = 1; i <= pArr[0]; i++)
	{
		std::cout << pArr[i] << " ";
	}
	std::cout << std::endl;
#endif
	delete[] pArr;
}