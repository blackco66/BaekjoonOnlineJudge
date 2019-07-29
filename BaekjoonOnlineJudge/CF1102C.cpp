#include<iostream>
using namespace std;
int main()
{
	int n,x,y;
	cin >> n>> x>> y;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp <= x)count++;
	}
	if (x > y)cout << n;
	else
	{
		cout << (count + 1) / 2;
	}
	return 0;
}