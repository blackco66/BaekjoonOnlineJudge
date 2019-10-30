#include <iostream>
using namespace std;
int n, m;
char p[50][50];
bool visited[50][50];
bool dfs(int r, int c) {

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> p[i][j];
			visited[i][j] = false;
		}
	}
	bool ans = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) continue;
			ans = dfs(i, j);
		}
	}
	return 0;
}