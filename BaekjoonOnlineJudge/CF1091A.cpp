#include<iostream>
using namespace std;

int main()
{
	int y, b, r;
	cin >> y >> b >> r;
	b -= 1;
	r -= 2;
	int min = y;
	if (min > b) min = b;
	if (min > r) min = r;
	cout << min * 3 + 3;
	return 0;
}