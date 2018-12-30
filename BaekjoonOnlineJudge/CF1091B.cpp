#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	__int64 x = 0;
	__int64 y = 0;
	int tempx, tempy;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> tempx >> tempy;
		x += tempx;
		y += tempy;
	}
	cout << x / n << " " << y / n;
	return 0;
}