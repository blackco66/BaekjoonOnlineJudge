#include <bits/stdc++.h>
using namespace std;
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int x1, x2, v1, v2;
	cin >> x1 >> v1 >> x2 >> v2;
	int xx = x1 - x2;
	int vv = v1 - v2;
	if (xx == 0) {
		cout << "YES";
		return 0;
	}
	else if (vv * xx >= 0) {
		cout << "NO";
		return 0;
	}
	xx = xx > 0 ? xx : -xx;
	vv = vv > 0 ? vv : -vv;
	if (xx % vv == 0) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}