#pragma  once

void ccccc(char* pData, int len)
{
	int j = 0;
	for (j = 0; j < len / 2; j++)
	{
		char c = pData[j];
		pData[j] = pData[len - j - 1];
		pData[len - j - 1] = c;
	}

}

void count_to_bits(unsigned int nNum, int jinzhi, char* pData, int& nLen)
{
	nLen = 0;
	while(nNum)
	{
		pData[nLen] = (nNum % jinzhi + '0');
		nNum = nNum / jinzhi;
		nLen++;
	}
	ccccc(pData, nLen);
}

std::string dtox(int digital, int r) {
	std::string result = "";
	const char s[37] = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (digital == 0) {
		return "0";
	}
	while (digital != 0) {
		int tmp = digital % r;
		result += s[tmp];
		digital /= r;
	}
	std::reverse(result.begin(), result.end());
	return result;
}