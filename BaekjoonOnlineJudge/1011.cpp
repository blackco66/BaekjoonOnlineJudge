///1011
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int t; cin >> t;
	for (int tc = 0; tc < t; tc++) 
	{
		int a, b; 
		cin >> a >> b;
		int diff = b - a;
		int sq = sqrt(diff);
		int mid = sq * (sq + 1);
		if (diff > mid) cout << sq * 2 + 1;
		else if (diff == sq * sq)cout << sq * 2 - 1;
		else cout << sq * 2;

		if (tc == t - 1)break;
		cout << endl;
	}
	return 0;
}