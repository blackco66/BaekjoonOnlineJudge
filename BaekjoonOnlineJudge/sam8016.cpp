#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		long long n;
		cin >> n;
		long long a = 2 * (n - 1) * (n - 1) + 1;
		long long b = 2 * n * n - 1;
		cout << "#" << tt+1 << " " << a << " " << b << endl;
	}
	return 0;
}