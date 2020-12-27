#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

///大数加法
std::string BigdigitAdd(std::string sOne, std::string sTwo)
{
	int nNum1Len = sOne.length();
	int nNum2Len = sTwo.length();
	int nMaxLen = std::max(nNum1Len, nNum2Len);

	int nArrLen = nMaxLen + 5;
	int* pArr1 = new int[nArrLen];
	memset(pArr1, 0, sizeof(int) * nArrLen);
	int* pArr2 = new int[nArrLen];
	memset(pArr2, 0, sizeof(int) * nArrLen);
	int* pSum = new int[nArrLen];
	memset(pSum, 0, sizeof(int) * nArrLen);

	//数组一记录
	for (int i = nNum1Len - 1, j = 0; i >= 0; i--, j++)
	{
		pArr1[j] = sOne[i] - '0';
	}

	//数组二记录
	for (int i = nNum2Len - 1, j = 0; i >= 0; i--, j++)
	{
		pArr2[j] = sTwo[i] - '0';
	}

	//数据求和
	for (int i = 0 ;i < nMaxLen; i++)
	{
		pSum[i] = pSum[i] + pArr1[i] + pArr2[i];
		if (pSum[i] > 9)
		{
			pSum[i + 1] += (pSum[i] / 10);
			pSum[i] %= 10;

			if (i + 1 == nMaxLen)
			{
				nMaxLen++;
				break;
			}
		}
	}

	std::string sAns = "";
	for (int i = nMaxLen - 1; i >= 0; i--)
	{
		sAns += std::to_string(pSum[i]);
	}
	delete[] pArr1;
	delete[] pArr2;

	return sAns;
}


///大数乘法
std::string BigdigitProduct(std::string sOne, std::string sTwo)
{
	int nNum1Len = sOne.length();
	int nNum2Len = sTwo.length();
	int nMaxLen = nNum1Len + nNum2Len - 1;

	int nArrLen = nMaxLen + 5;
	int* pArr1 = new int[nArrLen];
	memset(pArr1, 0, sizeof(int) * nArrLen);
	int* pArr2 = new int[nArrLen];
	memset(pArr2, 0, sizeof(int) * nArrLen);
	int* pSum = new int[nArrLen];
	memset(pSum, 0, sizeof(int) * nArrLen);

	//数组一记录
	for (int i = nNum1Len - 1, j = 0; i >= 0; i--, j++)
	{
		pArr1[j] = sOne[i] - '0';
	}

	//数组二记录
	for (int i = nNum2Len - 1, j = 0; i >= 0; i--, j++)
	{
		pArr2[j] = sTwo[i] - '0';
	}

	//数据求积
	for (int i = 0; i < nNum1Len; i++)
	{
		for (int j = 0; j < nNum2Len; j++)
		{
			pSum[i + j] = pArr1[i] * pArr2[j];
		}
	}

	for (int i = 0; i < nMaxLen; i++)
	{
		if (pSum[i] > 9)
		{
			pSum[i + 1] += (pSum[i] / 10);
			pSum[i] %= 10;

			if (i + 1 == nMaxLen)
			{
				nMaxLen++;
			}
		}
	}

	std::string sAns = "";
	for (int i = nMaxLen - 1; i >= 0; i--)
	{
		sAns += std::to_string(pSum[i]);
	}
	delete[] pArr1;
	delete[] pArr2;

	return sAns;
}

void BigdigitTest()
{
	//std::cout << BigdigitAdd("99", "21");
	std::cout << BigdigitProduct("20", "500");
}