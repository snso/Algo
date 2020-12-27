#pragma once

unsigned long Euler_1_Mult3And5(int nMax)
{
	//等差数列求和
#if 0
	unsigned long sum = 0;
	for (int i = 1; i < nMax; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	return sum;
#endif
	int sum3 = (3 + 999) * 333 / 2;
	int sum5 = (5 + 995) * 199 / 2;
	int sum15 = (15 + 990) * 66 / 2;
	return sum3 + sum5 - sum15;
}

unsigned long Euler_2_EvenFibonacciNumber(unsigned int nMax)
{
	unsigned long sum = 0;
	unsigned int a = 1, b = 2;
	while (b <= nMax)
	{
		if (b % 2 == 0)
		{
			sum += b;
		}
		b = a + b;
		a = b - a;
		
	}
	return sum;
}

unsigned int Euler_3_MaxPrime(unsigned long long nMax)
{
	unsigned int nRet = 0;
	int i = 2;
	while (nMax > 2)
	{
		if (nMax % i == 0)
		{
			nMax /= i;
			nRet = i;
		}
		else
		{
			i++;
		}
	}
	return nRet;
}

int NumReverse(int nNum)
{
	int nRet = 0;
	while (nNum > 0)
	{
		nRet = nRet * 10 + nNum % 10;
		nNum /= 10;
	}
	return nRet;
}

unsigned int Euler_4_LargetPalindrome(int nMax, int nMin)
{
	int nMaxPalinedrome = 0;
	for (int i = nMax; i >= nMin; i--)
	{
		for (int j = i; j >= nMin; j--)
		{
			int nRet = i * j;
			if (nRet == NumReverse(nRet))
			{
				nMaxPalinedrome = std::max(nRet, nMaxPalinedrome);
			}
		}
	}
	return nMaxPalinedrome;
}

unsigned int Euler_5_MinMultiple(int nMin, int nMax)
{
	unsigned int nCount = nMax;
	for (;; nCount++)
	{
		bool bRet = true;
		for (int j = nMin; j <= nMax; j++)
		{
			if (nCount % j != 0)
			{
				bRet = false;
				break;
			}
		}
		if (bRet) break;
	}
	return nCount;
}

unsigned int Euler_6_SumQuare(int nNum)
{
	unsigned int nSum = 0, nPsum = 0;
	bool bRet = true;
	for (int i = 1; i <= 100; i++)
	{
		nSum += i;
		nPsum += (i * i);
	}
	return nSum * nSum - nPsum;
}

unsigned int Euler_7_PrimeNum(int nIndex)
{
	int nNum = nIndex * 20;
	unsigned int* pArr = new unsigned int[nNum + 1];
	memset(pArr, 0, sizeof(unsigned int) * (nNum + 1));
	for (int i = 2; i <= nNum; i++)
	{
		if(pArr[i]) continue;
		pArr[++pArr[0]] = i;
		if(pArr[0] >= nIndex) break;
		for (unsigned int j = i * i; j <= nNum; j+=i)
		{
			pArr[j] = 1;
		}
	}

	unsigned int nRet = pArr[pArr[0]];
	delete[] pArr;
	return nRet;
}

unsigned long long Euler_8_MaxProduct(const int* pArr,const int nNum, const int nMaxCount)
{
	unsigned long long nMaxProjuct = 0;
	unsigned long long nProjuct = 1;
	int nZeroNum = 0;
	
	for (int i = 0; i < nNum; i++)
	{
		if (i < nMaxCount)
		{
			nProjuct *= pArr[i];
			if (pArr[i] == 0) nZeroNum++;
		}
		else
		{
			if (pArr[i] == 0) nZeroNum++;
			else nProjuct *= pArr[i];
			
			if (pArr[i - nMaxCount] == 0) nZeroNum--;
			else nProjuct /= pArr[i - nMaxCount];
		}
		if (nZeroNum == 0) nMaxProjuct = std::max(nMaxProjuct, nProjuct);
	}
	return nMaxProjuct;
}


//方向数组
/*
{-1,-1}		{0,-1}		{1,-1}
{-1,0}		{0,0}		{1,0}
{-1,1}		{0,1}		{1,1}


			{1,-1}
{0, 0}		{1,0}
{0, 1}		{1,1}
			

*/
unsigned long long Euler_11_MaxProductInGrid(const int pArr[][30], const int nRow, const int nCol, const int nPadding)
{
	const int nMaxNum = 4;
	int nDir[nMaxNum][2] = { {1,-1}, {1,0}, {1,1}, {0,1} };
	long long lMaxProduct = 0;

	for (int i = nPadding; i < nRow - nPadding; i++)
	{
		for (int j = nPadding; j < nCol - nPadding; j++)
		{
			//遍历每个方向
			for (int m = 0; m < 4; m++)
			{
				long long nProduct = 1;
				//求和
				for (int n = 0; n < nMaxNum; n++)
				{
					int data = pArr[i + nDir[m][0] * n][j + nDir[m][1] * n];
					nProduct *= data;
				}

				lMaxProduct = std::max(lMaxProduct, nProduct);
			}
		}
	}
	return lMaxProduct;
}


int* pArrData = nullptr;
int nLen = 0;

int CollztzLen(long long nNum)
{
	if (nNum == 1)  return 1;
	if (nNum < nLen && pArrData[nNum]) return pArrData[nNum];
	int nIndex = 0;
	if (nNum % 2 == 0)
	{
		nIndex = CollztzLen(nNum / 2) + 1;
	}
	else
	{
		nIndex = CollztzLen(nNum * 3 + 1) + 1;
	}

	if (nNum < nLen)
	{
		pArrData[nNum] = nIndex;
	}
	return nIndex;
}

long long Euler_14_LongestCollatz(long long nNum)
{
	long long lMaxRet = 0;
	int nMaxIndex = 0;
	pArrData = new int[nNum];
	memset(pArrData, 0 , sizeof(int) * nNum);
	nLen = nNum;
	for (int i = 2; i < nNum; i++)
	{
		long long lRet = CollztzLen(i);
		if (lRet > lMaxRet)
		{
			lMaxRet = lRet;
			nMaxIndex = i;
		}
	}

	delete[] pArrData;
	nLen = 0;
	return nMaxIndex;
}

void EulerTest()
{
	/*1.Multiples of 3 and 5 3和5的倍数 */
	//std::cout << Euler_1_Mult3And5(1000);

	/*2.Even Fibonacci numbers 斐波纳契数*/
	//std::cout << Euler_2_EvenFibonacciNumber(4000000);

	/*3.Largest prime factor 最大的质因数*/
	//std::cout << Euler_3_MaxPrime(600851475143);

	/*4.Largest palindrome product 最大回文数*/
	//std::cout << Euler_4_LargetPalindrome(999,100);

	/*5.Smallest multiple*/
	//std::cout << Euler_5_MinMultiple(1, 20);

	/*6.Sum square difference*/
	//std::cout << Euler_6_SumQuare(10);

	/*7.10001st prime*/
	//std::cout << Euler_7_PrimeNum(10001);

	/*8.Largest product in a series 连续数字最大乘积*/
	//int nNum = 1000;
	//int* pArr = new int[nNum];
	//char cData[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	//for (int i = 0; i < nNum; i++)
	//{
	//	char ch = *(cData + i);
	//	pArr[i] = atoi(&ch);
	//}
	//std::cout << Euler_8_MaxProduct(pArr, nNum, 13);



	/*11.Largest product in a grid*/
	/*
	const int nArr[30][30] = {\
	{ 00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00 },\
	{ 00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00 },\
	{ 00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00 },\
	{ 00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00 },\
	{ 00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00 },\
	{ 00,00,00,00,00,8,02,22,97,38,15,00,40,00,75,04,05,07,78,52,12,50,77,91,8,00,00,00,00,00 },\
	{ 00,00,00,00,00,49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00,00,00,00,00,00 },\
	{ 00,00,00,00,00,81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65,00,00,00,00,00 },\
	{ 00,00,00,00,00,52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91,00,00,00,00,00 },\
	{ 00,00,00,00,00,22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80,00,00,00,00,00 },\
	{ 00,00,00,00,00,24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50,00,00,00,00,00 },\
	{ 00,00,00,00,00,32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70,00,00,00,00,00 },\
	{ 00,00,00,00,00,67,26,20,68,02,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21,00,00,00,00,00 },\
	{ 00, 00, 00, 00, 00, 24, 55, 58, 05, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 21, 36, 23, 9, 75, 00, 76, 44, 20, 45, 35, 14, 00, 61, 33, 97, 34, 31, 33, 95, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 04, 62, 16, 14, 9, 53, 56, 92, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 16, 39, 05, 42, 96, 35, 31, 47, 55, 58, 88, 24, 00, 17, 54, 24, 36, 29, 85, 57, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 86, 56, 00, 48, 35, 71, 89, 07, 05, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 19, 80, 81, 68, 05, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 04, 89, 55, 40, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 04, 52, 8, 83, 97, 35, 99, 16, 07, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 88, 36, 68, 87, 57, 62, 20, 72, 03, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 04, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 04, 36, 16, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 20, 73, 35, 29, 78, 31, 90, 01, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 05, 54, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 01, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 01, 89, 19, 67, 48, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00 }, \
	{ 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00 } };
	std::cout << Euler_11_MaxProductInGrid(nArr, 30,30, 5);
	*/

	/*14.Longest Collatz sequence*/
	std::cout << Euler_14_LongestCollatz(1000000);


}