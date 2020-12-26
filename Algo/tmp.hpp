#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main11()
{
	int n;
	int* pData = NULL;
	int i = 0;
	int j = 0;
	scanf("%d", &n);

	pData = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &(pData[i]));
	}

	for (i = 1; i < n; i++)
	{
		int nMin = -1;
		int nIndex = 0;

		for (j = 0; j < i; j++)
		{
			if (i == j) continue;
			int diff = abs(pData[i] - pData[j]);
			if (diff < nMin || nMin == -1)
			{
				nMin = diff;
				nIndex = j;
			}
		}
		printf("%d %d", nMin, nIndex + 1);
		i != n - 1 && printf("\n");
	}

	if (pData)
	{
		free(pData);
	}
	return 0;
}