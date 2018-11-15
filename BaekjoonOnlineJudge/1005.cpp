//1005
#include<iostream>

int main()
{
	int t;
	for (int tc = 0; tc < t; tc++)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		int* time = new int[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &time[i]);
		}
		if (time) delete time;
	}
}