#include<iostream>
using namespace std;
int n;
int a[15];

int sum[64 * 1024 - 1];

int main()
{
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int c = 1;
	int count = 1;
	sum[0] = 0;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int in = count + j*2;
			sum[in] = (sum[in / 2] + a[i])%360;
			sum[in + 1] = (sum[in / 2] - a[i])%360;
			if (i == n - 1)
			{
				if (sum[in] == 0 || sum[in + 1] == 0) 
				{
					flag = true;
					break;
				}
			}
		}
		c *= 2;
		count += c;
	}
	if (flag == true) cout << "YES";
	else cout << "NO";
	return 0;
}