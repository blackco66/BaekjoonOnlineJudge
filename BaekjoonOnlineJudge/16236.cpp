#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int a[20][20];
	int sharkx, sharky;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			a[i][j] = tmp;
			if (tmp == 9) {
				sharkx = i;
				sharky = j;
				a[i][j] = 0;
			}
		}
	}

	return 0;
}