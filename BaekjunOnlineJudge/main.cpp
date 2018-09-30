///#1002

#include <iostream>




int main()
{
	int n;
	scanf("%d", &n);
	int fib[41];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < 41; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	for (int i = 0; i < n; i++)
	{
		int f;
		scanf("%d", &f);
		if (f == 0)std::cout << 1 << " " << 0 << std::endl;
		else
		{
			std::cout << fib[f - 1] << " " << fib[f] << std::endl;
		}
	}
	return 0;
}

