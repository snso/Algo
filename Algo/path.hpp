#pragma  once

#include <iostream>
#include <stdio.h>
#include <queue>

int n, m, sx, sy;
int dir[][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char mmap[105][105];

struct node
{
	int x, y, step;
};

int func_2(int x, int y)
{
	std::queue<node> que;
	que.push(node{x, y, 0});
	while (!que.empty())
	{
		node tmp = que.front();
		que.pop();
		for (int i = 0 ; i < 4; i++)
		{
			int xx = tmp.x + dir[i][0];
			int yy = tmp.y + dir[i][1];

			if (mmap[xx][yy] == 'T')
			{
				std::cout << tmp.step + 1;
				return 1;
			}

			if (mmap[xx][yy] == '.')
			{
				que.push(node{ xx, yy, tmp.step + 1 });
				mmap[xx][yy] = 0;
			}
		}
	}
	std::cout << "No" << std::endl;
	return 0;
}


int func(int x, int y)
{
	for (int i = 0 ; i < 4; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];

		if (mmap[xx][yy] == 'T')
		{
			return 1;
		}

		if (mmap[xx][yy] == '.')
		{
			mmap[xx][yy] = '#';
			if (func(xx, yy))
			{
				return 1;
			}
		}
	}
	return 0;
}

int Test_path()
{
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			std::cin >> mmap[i][j];
			if (mmap[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
		}
	}

	if (func_2(sx, sy))
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}

	return 0;
}

