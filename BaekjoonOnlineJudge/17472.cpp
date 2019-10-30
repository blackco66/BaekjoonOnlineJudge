#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int map[10][10];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
void colormap(int island, int r, int c) {
	map[r][c] = island;
	for (int i = 0; i < 4; i++) {
		int yy = r + dy[i];
		int xx = c + dx[i];
		if (yy < 0 || xx < 0 || yy >= N || xx >= M || map[yy][xx] >= 0) continue;
		colormap(island, yy, xx);
	}
}
int bridgelength(int bridenum) {
	int bridge1 = bridenum / 6 + 1;
	int bridge2 = bridenum % 6 + bridge1;
	int len = 10;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != bridge1)continue;
			for (int k = 0; k < N; k++) {
				if (map[k][j] != bridge2)continue;
				bool land = false;
				int min = i > k ? k : i;
				int max = i > k ? i : k;
				for (int l = min + 1; l < max; l++) {
					if (map[l][j] != 0) {
						land = true;
						break;
					}
				}
				if (land)continue;
				int tmplen = i > k ? i - k - 1 : k - i - 1;
				if (tmplen > 1 && tmplen < len)len = tmplen;
			}
			for (int k = 0; k < M; k++) {
				if (map[i][k] != bridge2)continue;
				bool land = false;
				int min = j > k ? k : j;
				int max = j > k ? j : k;
				for (int l = min + 1; l < max; l++) {
					if (map[i][l] != 0) {
						land = true;
						break;
					}
				}
				if (land)continue;
				int tmplen = j > k ? j - k - 1 : k - j - 1;
				if (tmplen > 1 && tmplen < len)len = tmplen;
			}
		}
	}
	return len;
}
int getparent(int set[], int x) {
	if (set[x] == x)return x;
	return set[x] = getparent(set, set[x]);
}
void unionparent(int set[], int a, int b) {
	a = getparent(set, a);
	b = getparent(set, b);
	if (a < b)set[b] = a;
	else set[a] = b;
}
bool find(int set[], int a, int b) {
	a = getparent(set, a);
	b = getparent(set, b);
	if (a == b)return true;
	return false;
}
class edge {
public:
	int node[2];
	int distance;
	edge(int a, int b, int dist) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = dist;
	}
	bool operator<(edge& edge) {
		return this->distance < edge.distance;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			map[i][j] = -map[i][j];
		}
	}
	int island = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != -1)continue;
			island++;
			colormap(island, i, j);
		}
	}
	vector<edge> v;
	for (int i = 1; i < island; i++) {
		for (int j = i + 1; j <= island; j++) {
			int bridgenum = 6 * (i - 1) + (j - i); 
			int tmplength = bridgelength(bridgenum);
			if (tmplength == 10)continue;
			v.push_back(edge(i, j, tmplength));
		}
	}
	int set[7];
	for (int i = 1; i < 7; i++) {
		set[i] = i;
	}
	sort(v.begin(), v.end());
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(set, v[i].node[0], v[i].node[1])) {
			sum += v[i].distance;
			unionparent(set, v[i].node[0], v[i].node[1]);
			cnt++;
		}
	}
	bool flag = false;
	if (cnt != island - 1) {
		cout << -1;
	}
	else {
		cout << sum;
	}
	return 0;
}