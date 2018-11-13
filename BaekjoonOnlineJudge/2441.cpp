///#2441
#include<iostream>
using namespace std;

int main() 
{
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		int re_n = n - i;
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < re_n; j++) 
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}