//1929
#include<iostream>
#include<cmath>
bool DiscriminatePrime(int p)
{
	int sqrtP = sqrt(p);
	if (p == 1) return false;
	for (int i = 2; i <= sqrtP; i++)
	{
		if (p % i == 0 && p != i) return false;
	}
	return true;
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = n; i <= m; i++)
	{
		if (DiscriminatePrime(i))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}