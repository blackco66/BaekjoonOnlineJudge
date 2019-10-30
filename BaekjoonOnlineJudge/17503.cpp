#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
vector<vector<int>> beer(10001);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	int up = -1;
	int down = 2147483647;
	for (int i = 0; i < K; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		beer[tmp1].push_back(tmp2);
		if (up < tmp2)up = tmp2;
		if (down > tmp2) down = tmp2;
	}
	int lev = (up + down) / 2;
	bool flag = false;
	while (1) {
		int prefer = 0;
		int cnt = 0;
		for (int i = 10001; i >= 0; i--) {
			if (beer[i].size() == 0)continue;
			for (int blev : beer[i]) {
				if (blev > lev)continue;
				prefer += i;
				cnt++;
				if (cnt == N)break;
			}
			if (cnt == N)break;
		}
		if (cnt == N && prefer>=M) {
			up = lev;
			lev = (up + down) / 2;
		}
		else if
		
	}
	else cout << level + 1;
	
	return 0;
}