///#2439
#include<iostream>
using namespace std;

int main() {
	int n; 
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		int re_n = n - i;
		for (int j = 0; j < re_n; j++) 
		{
			printf(" ");
		}
		for (int j = 0; j < i; j++) 
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}