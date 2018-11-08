///#1275
#include<iostream>

int a[100000];

void Swap(int &a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Turn()
{
	int begin, end, cgIndex, cgNum;
	long long int sum = 0;
	scanf("%d %d %d %d", &begin, &end, &cgIndex, &cgNum);
	if (begin > end)
	{
		Swap(begin, end);
	}
	for (int i = begin; i <= end; i++)
	{
		sum += a[i - 1];
	}
	printf("%lld\n", sum);
	a[cgIndex - 1] = cgNum;
}

int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < Q; i++)
	{
		Turn();
	}
	return 0;
}