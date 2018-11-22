//1463
#include<iostream>
int numOfCalculation[1000001];
int main()
{
	int n;
	scanf("%d", &n);
	numOfCalculation[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int calA = 10000000;
		int calB = 10000000;
		int calC = 10000000;
		if (i % 3 == 0) calA = numOfCalculation[i / 3];
		if (i % 2 == 0) calB = numOfCalculation[i / 2];
		calC = numOfCalculation[i - 1];
		if (calA <= calB&&calA <= calC) numOfCalculation[i] = numOfCalculation[i / 3] + 1;
		else if(calB <= calA&&calB <= calC) numOfCalculation[i] = numOfCalculation[i / 2] + 1;
		else numOfCalculation[i] = numOfCalculation[i - 1] + 1;
	}
	printf("%d\n", numOfCalculation[n]);
	return 0;
}