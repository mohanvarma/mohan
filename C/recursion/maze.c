#include <stdio.h>
int maze[4][4] = {{1,0,1,1},
				{1,1,0,1},
				{1,1,1,0},
				{0,0,1,1}};
int maximum(int a, int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

int find_longest(int x, int y)
{
	int max = 0;

	if(x>3 || y>3)
		return max;

	if(x==3 && y==3)
	{
		max = max+maze[x][y];
		return max;
	}

	if (maze[x][y] == 0)
		return max;

	max = maximum(find_longest(x+1,y), find_longest(x, y+1))+1;
}

int main()
{
	printf("%d", find_longest(0,0));
	return  0;
}
