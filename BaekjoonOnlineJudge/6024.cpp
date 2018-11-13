///6024
#include<iostream>

int main() 
{
	int t; scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) 
	{
		int M, N, x, y;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		int year = x;
		while(true) 
		{
			if (year%N == y%N) break;
			year += M;
			if (year == M * N + x + M) break;
		}
		if (year == M * N + x + M) printf("-1\n");
		else printf("%d\n", year);
	}
}