#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool map[625];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> numHome;
	for (int i = 0; i < n * n; i++) {
		char tmp;
		cin >> tmp;
		map[i] = (tmp == '1');
	}
	for (int i = 0; i < n * n; i++) {
		if (map[i]) {
			int num = 0;
			queue<int> q;
			q.push(i);
			map[i] = false;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				num++;
				if (cur % n != 0 && map[cur - 1]) {
					q.push(cur - 1);
					map[cur - 1] = false;
				}
				if (cur % n != n - 1 && map[cur + 1]) {
					q.push(cur + 1);
					map[cur + 1] = false;
				}
				if (cur / n != 0 && map[cur - n]) {
					q.push(cur - n);
					map[cur - n] = false;
				}
				if (cur / n != n - 1 && map[cur + n]) {
					q.push(cur + n);
					map[cur + n] = false;
				}
			}
			numHome.push_back(num);
		}
	}
	sort(numHome.begin(), numHome.end());
	cout << numHome.size() << endl;
	for (int i = 0; i < numHome.size(); i++) {
		cout << numHome[i] << endl;
	}
	return 0;
}