//1676
#include<iostream>
int FactorialZeros(int n)
{
	int fives = 5;
	int zeros = 0;
	while (fives < n)
	{
		zeros += (n / fives);
		fives *= 5;
	}
	return zeros;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", FactorialZeros(n));
	return 0;
}