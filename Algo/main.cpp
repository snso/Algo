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
#include <iomanip>

#include <stddef.h>
#include <stdint.h>

#include "VzTimeUtils.h"
#include "sort.hpp"
#include "prime.hpp"
#include "euler.hpp"
#include "bigdigit.hpp"


#define TYPE_STR(a) _Generic((a),\
	int : "%d",\
	double : "%lf",\
	char : "%c",\
	char * : "%s"\
)

void SortArr()
{
	const int LEN = 10;
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
	std::cout << std::endl;
	SortPrint(insertArr, LEN);
	delete[] insertArr;
	std::cout << "SortInsert:" << cvTimeUtils.GetElapsedTimeInMilliSec() << std::endl << std::endl;

	int* bubbleArr = new int[LEN];
	memcpy(bubbleArr, arr, sizeof(int) * LEN);
	SortPrint(bubbleArr, LEN);
	cvTimeUtils.Update();
	SortBubble(bubbleArr, LEN);
	std::cout << std::endl;
	SortPrint(bubbleArr, LEN);
	delete[] bubbleArr;
	std::cout << "SortBubble:" << cvTimeUtils.GetElapsedTimeInMilliSec() << std::endl << std::endl;

	int* mergeArr = new int[LEN];
	memcpy(mergeArr, arr, sizeof(int) * LEN);
	SortPrint(mergeArr, LEN);
	cvTimeUtils.Update();
	SortMerge(mergeArr,0, LEN - 1);
	std::cout << std::endl;
	SortPrint(mergeArr, LEN);
	delete[] mergeArr;
	std::cout << "SortMerge:" << cvTimeUtils.GetElapsedTimeInMilliSec() << std::endl << std::endl;


	int* selectArr = new int[LEN];
	memcpy(selectArr, arr, sizeof(int) * LEN);
	SortPrint(selectArr, LEN);
	cvTimeUtils.Update();
	SortSelect(selectArr, LEN);
	std::cout << std::endl;
	SortPrint(selectArr, LEN);
	delete[] selectArr;
	std::cout << "SortSelect:" << cvTimeUtils.GetElapsedTimeInMilliSec() << std::endl << std::endl;

	int* quickArr = new int[LEN];
	memcpy(quickArr, arr, sizeof(int) * LEN);
	SortPrint(quickArr, LEN);
	cvTimeUtils.Update();
	SortQuick(quickArr, 0 , LEN - 1);
	std::cout << std::endl;
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

int Test()
{
	#define PI 3.14
	int a, b, c, t;
	std::cin >> a >> b >> c >> t;
	std::cout << std::fixed << std::setprecision(2) <<
		((1.00 * a * b * c - (b * c + a * c) * t) / (b * c + a * c - a * b) + t);
	return 0;
}

int main()
{
	CVzTimeUtils oTimeUtils;
	oTimeUtils.Update();
	SortArr();
	//Prime();
	//EulerTest();
	//BigdigitTest();
	std::cout << std::endl << "run:" << oTimeUtils.GetElapsedTimeInMilliSec() << "ms";
	getchar();
	return 0;
}