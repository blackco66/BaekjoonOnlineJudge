#include<bits/stdc++.h>
using namespace std;

const int MAX = 650;
bool tray[MAX * MAX];
int N, M, K;

int main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
		int ans = 0;
		cin >> N >> M >> K;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				tray[i * MAX + j] = false;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int tmp;
				cin >> tmp;
				if (tmp) {
					tray[(300 + i) * MAX + (300 + j)] = true;

				}

			}
		}
		cout << "#" << tt << " " << ans;
	}
	return 0;
}