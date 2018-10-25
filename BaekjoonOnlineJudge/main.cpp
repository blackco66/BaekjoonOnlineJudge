///#5624

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
bool check[400001];
const int BASE = 200000;
int main() {
	for (int i = 0; i <= 400000; i++) {
		check[i] = false;
	}
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i<n; i++) {
		bool ok = false;
		for (int j = 0; j<i; j++) {
			if (check[a[i] - a[j] + BASE]) {
				ok = true;
			}
		}
		if (ok) ans += 1;
		for (int j = 0; j <= i; j++) {
			check[a[i] + a[j] + BASE] = true;
		}
	}
	cout << ans << '\n';
	return 0;
}