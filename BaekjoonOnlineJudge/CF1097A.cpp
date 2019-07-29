#include<iostream>
using namespace std;


int main()
{
	char t_1, t_2;
	char h1[5], h2[5];
	cin >> t_1 >> t_2;
	bool flag = false;
	for (int i = 0; i < 5; i++)
	{
		cin >> h1[i] >> h2[i];
		if (h1[i] == t_1) flag = true;
		if (h2[i] == t_2) flag = true;
	}
	if (flag == true) cout << "YES";
	else cout << "NO";
	
	return 0;
}