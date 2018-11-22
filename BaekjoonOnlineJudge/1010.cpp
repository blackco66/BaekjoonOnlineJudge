//1010
#include<iostream>

int Combination(int n, int r)
{
	int ans = 1;
	for (int i = 0; i < n - r; i++)
	{
		ans *= (n - i);
		ans /= (i + 1);
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++)
	{
		int n, r;
		scanf("%d %d", &r, &n);
		printf("%d\n", Combination(n, r));
	}
	return 0;
}