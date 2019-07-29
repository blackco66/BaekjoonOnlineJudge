#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	char a[3 * 100000];
	int c0, c1, c2;
	c0 = c1 = c2 = 0;
	int c = n / 3;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == '0')c0++;
		else if (a[i] == '1')c1++;
		else c2++;
	}
	if (c0 == c)
	{
		if (c1 > c2)
		{
			int diff = (c1 - c2) / 2;
			int it = n - 1;
			while (diff > 0)
			{
				if (a[it] == '1')
				{
					a[it] = '2';
					diff--;
				}
				it--;
			}
		}
		else
		{
			int diff = (c2 - c1) / 2;
			int it = 0;
			while (diff > 0)
			{
				if (a[it] == '2')
				{
					a[it] = '1';
					diff--;
				}
				it++;
			}
		}
	}
	else if (c1 == c)
	{
		if (c0 > c2)
		{
			int diff = (c0 - c2) / 2;
			int it = n - 1;
			while (diff > 0)
			{
				if (a[it] == '0')
				{
					a[it] = '2';
					diff--;
				}
				it--;
			}
		}
		else
		{
			int diff = (c2 - c0) / 2;
			int it = 0;
			while (diff > 0)
			{
				if (a[it] == '2')
				{
					a[it] = '0';
					diff--;
				}
				it++;
			}
		}
	}
	else if (c2 == c)
	{
		if (c0 > c1)
		{
			int diff = (c0 - c1) / 2;
			int it = n - 1;
			while (diff > 0)
			{
				if (a[it] == '0')
				{
					a[it] = '1';
					diff--;
				}
				it--;
			}
		}
		else
		{
			int diff = (c1 - c0) / 2;
			int it = 0;
			while (diff > 0)
			{
				if (a[it] == '1')
				{
					a[it] = '0';
					diff--;
				}
				it++;
			}
		}
	}
	else if (c0 > c&&c1 > c)
	{
		int it = n - 1;
		int diff0 = c0 - c;
		int diff1 = c1 - c;
		while (diff0 + diff1 > 0)
		{
			if (a[it] == '0' && diff0 > 0)
			{
				a[it] = '2';
				diff0--;
			}
			else if (a[it] == '1' && diff1 > 0)
			{
				a[it] = '2';
				diff1--;
			}
			it--;
		}
	}
	else if (c0 > c&&c2 > c)
	{
		int it = n - 1;
		int diff0 = c0 - c;
		int diff2 = c2 - c;
		while (diff0 > 0)
		{
			if (a[it] == '0')
			{
				a[it] = '1';
				diff0--;
			}
			it--;
		}
		it = 0;
		while (diff2 > 0)
		{
			if (a[it] == '2')
			{
				a[it] = '1';
				diff2--;
			}
			it++;
		}
	}
	else if (c1 > c&&c2 > c)
	{
		int it = 0;
		int diff1 = c1 - c;
		int diff2 = c2 - c;
		while (diff1 + diff2 > 0)
		{
			if (a[it] == '1' && diff1 > 0)
			{
				a[it] = '0';
				diff1--;
			}
			else if (a[it] == '2' && diff2 > 0)
			{
				a[it] = '0';
				diff2--;
			}
			it++;
		}
	}
	else if (c0 < c&&c1 < c)
	{
		int diff0 = c - c0;
		int diff1 = c - c1;
		int it = 0;
		while (diff0 > 0)
		{
			if (a[it] == '2')
			{
				a[it] = '0';
				diff0--;
			}
			it++;
		}
		while (diff1 > 0)
		{
			if (a[it] == '2')
			{
				a[it] = '1';
				diff1--;
			}
			it++;
		}
	}
	else if (c0 < c&&c2 < c)
	{
		int diff0 = c - c0;
		int diff2 = c - c2;
		int it = 0;
		while (diff0 > 0)
		{
			if (a[it] == '1')
			{
				a[it] = '0';
				diff0--;
			}
			it++;
		}
		it = n - 1;
		while (diff2 > 0)
		{
			if (a[it] == '1')
			{
				a[it] = '2';
				diff2--;
			}
			it--;
		}
	}
	else if (c1 < c&&c2 < c)
	{
		int diff1 = c - c1;
		int diff2 = c - c2;
		int it = n-1;
		while (diff2 > 0)
		{
			if (a[it] == '0')
			{
				a[it] = '2';
				diff2--;
			}
			it--;
		}
		while (diff1 > 0)
		{
			if (a[it] == '0')
			{
				a[it] = '1';
				diff1--;
			}
			it--;
		}
	}



	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	return 0;
}