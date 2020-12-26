#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <ctime>

#include "VzTimeUtils.h"
#include "sort.hpp"
#include "prime.hpp"


void SortArr()
{
	const int LEN = 100000;
	CVzTimeUtils cvTimeUtils;
	srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	int* arr = new int[LEN];
	for (int i = 0; i < LEN; i++)
	{
		arr[i] = rand() % 1000;
	}

	int* insertArr = new int[LEN];
	memcpy(insertArr, arr, sizeof(int) * LEN);
	SortPrint(insertArr, LEN);
	cvTimeUtils.Update();
	SortInsert(insertArr, LEN);
	SortPrint(insertArr, LEN);
	delete[] insertArr;
	std::cout << "SortInsert:" << cvTimeUtils.GetElapsedTimeInMilliSec() << std::endl << std::endl;

	int* bubbleArr = new int[LEN];
	memcpy(bubbleArr, arr, sizeof(int) * LEN);
	SortPrint(bubbleArr, LEN);
	cvTimeUtils.Update();
	SortBubble(bubbleArr, LEN);
	SortPrint(bubbleArr, LEN);
	delete[] bubbleArr;
	std::cout << "SortBubble:" << cvTimeUtils.GetElapsedTimeInMilliSec() << std::endl << std::endl;

	int* selectArr = new int[LEN];
	memcpy(selectArr, arr, sizeof(int) * LEN);
	SortPrint(selectArr, LEN);
	cvTimeUtils.Update();
	SortSelect(selectArr, LEN);
	SortPrint(selectArr, LEN);
	delete[] selectArr;
	std::cout << "SortSelect:" << cvTimeUtils.GetElapsedTimeInMilliSec() << std::endl << std::endl;

	int* quickArr = new int[LEN];
	memcpy(quickArr, arr, sizeof(int) * LEN);
	SortPrint(quickArr, LEN);
	cvTimeUtils.Update();
	SortQuick(quickArr, LEN, LEN);
	SortPrint(quickArr, LEN);
	delete[] quickArr;
	std::cout << "SortQuick:" << cvTimeUtils.GetElapsedTimeInMilliSec() << std::endl << std::endl;

	delete[] arr;
}

void Prime()
{
	unsigned int nMax = 100000;
	CVzTimeUtils cvTimeUtils;
	cvTimeUtils.Update();
	Pramesift(nMax);
	std :: cout << "run : " << cvTimeUtils.GetElapsedTimeInMilliSec();

}

int main()
{
	SortArr();
	//Prime();
	getchar();
	return 0;
}