//9020
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
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int even;
		scanf("%d", &even);
		int a, b;
		a = b = even / 2;
		while (!(DiscriminatePrime(a) && DiscriminatePrime(b)))
		{
			a -= 1;
			b += 1;
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}