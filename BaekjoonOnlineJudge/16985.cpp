#include <iostream>
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
	int island = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != -1)continue;
			colormap(island, i, j);
			island++;
		}
	}
	int a = 1;
	return 0;
}