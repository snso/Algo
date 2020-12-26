#pragma once
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct UnionSet
{
	int *pColor;
	int nNum;
};

UnionSet* init(int nNum)
{
	UnionSet* pUnionSet = new UnionSet[nNum];
	pUnionSet->pColor = new int[nNum + 1];
	pUnionSet->nNum = nNum;
	for (int i = 0; i < nNum; i++)
	{
		pUnionSet->pColor[i] = i;
	}
	return pUnionSet;
}

int find(UnionSet* pUnionSet, int x)
{
	return pUnionSet->pColor[x] = (pUnionSet->pColor[x] == x ? x : find(pUnionSet, pUnionSet->pColor[x]));
}

int merge(UnionSet* pUnionSet, int a, int b)
{
	int fa = find(pUnionSet, a);
	int fb = find(pUnionSet, b);
	if (fa == fb) return 0;
	pUnionSet->pColor[fb] = fa;
	return 1;
}

void clear(UnionSet* pUnionSet)
{
	if (!pUnionSet) return;
	delete[] pUnionSet->pColor;
	delete[] pUnionSet;
}

int unionset()
{
	int n, m;
	std::cin >> n >> m;
	UnionSet* pUnionSet = init(n);
	for (int i = 0 ; i < m; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		switch (a)
		{
		case 1:
			merge(pUnionSet, b, c);
			break;
		case 2:
			std::cout << (find(pUnionSet, b) == find(pUnionSet, c) ? "Yes" : "No");
			break;
		default:
			break;
		}
	}
}

