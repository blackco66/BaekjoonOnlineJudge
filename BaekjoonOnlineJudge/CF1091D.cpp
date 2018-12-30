#include<iostream>
using namespace std;

int main()
{
	__int64 n;
	cin >> n;
	__int64 np = n;
	for (int i = 0; i < n; i++)
	{
		np = np * (i + 1) % 998244353;
	}
	__int64 ans = np;
	__int64 np2 = 1;
	__int64 nu = 0;
	for (int i = n; i > 1; i--)
	{
		np2 = np2 * i % 998244353;
		nu = (nu + np2) % 998244353;
	}
	ans = (ans - nu) % 998244353;
	cout << ans;
	return 0;
}