///#11720
#include<iostream>
using namespace std;

int main() 
{
	int n; cin >> n;
	int ans = 0;
	char temp1;
	scanf("%c", &temp1);
	for (int i = 0; i < n; i++)
	{
		char temp;
		scanf("%c", &temp);
		ans += (temp-'0');
	}
	printf("%d", ans);
	return 0;
}