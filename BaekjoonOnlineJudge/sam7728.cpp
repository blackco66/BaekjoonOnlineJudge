#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		int n;
		cin >> n;
		bool check[10] = { false };
		if (n == 1e9) {
			cout << "#" << tt + 1 << " " << 2 << endl;
			continue;
		}
		for (int i = 0; i < 9; i++) {
			int a = 1;
			for (int j = 0; j < i; j++) {
				a *= 10;
			}
			int b = a * 10;
			if (n < a)break;
			int c = (n % b - n % a)/a;
			check[c] = true;
		}
		int cnt = 0;
		for (int i = 0; i < 10; i++) {
			if (check[i])cnt++;
		}
		cout<< "#" << tt + 1 << " " << cnt << endl;
	}
	return 0;
}