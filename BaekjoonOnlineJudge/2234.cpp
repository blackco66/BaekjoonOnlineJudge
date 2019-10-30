#include <iostream>
#include <vector>
using namespace std;
int in[50][50];
int num[50][50];
bool visited[50][50];
int roomsize[2500];
void dfs(int r, int c, int number) {
	num[r][c] = number;
	roomsize[number] += 1;
	visited[r][c] = true;
	if (in[r][c] % 2 == 0 && !visited[r][c - 1])dfs(r, c - 1, number);
	if (in[r][c] / 2 % 2 == 0 && !visited[r - 1][c])dfs(r - 1, c, number);
	if (in[r][c] / 4 % 2 == 0 && !visited[r][c + 1])dfs(r, c + 1, number);
	if (in[r][c] / 8 % 2 == 0 && !visited[r + 1][c])dfs(r + 1, c, number);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> in[i][j]; 
			visited[i][j] = false;
		}
	}
	int number = 0;
	int maxroomsize = -1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j])continue;
			dfs(i, j, number);
			if (maxroomsize < roomsize[number])maxroomsize = roomsize[number];
			number += 1;
		}
	}
	int maxtworoom = -1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			if (i > 0 && num[i][j] != num[i - 1][j]) {
				tmp = roomsize[num[i][j]] + roomsize[num[i - 1][j]];
				maxtworoom = tmp > maxtworoom ? tmp : maxtworoom;
			}
			if (i < m - 1 && num[i][j] != num[i + 1][j]) {
				tmp = roomsize[num[i][j]] + roomsize[num[i + 1][j]];
				maxtworoom = tmp > maxtworoom ? tmp : maxtworoom;
			}
			if (j > 0 && num[i][j] != num[i][j - 1]) {
				tmp = roomsize[num[i][j]] + roomsize[num[i][j - 1]];
				maxtworoom = tmp > maxtworoom ? tmp : maxtworoom;
			}
			if (j < n - 1 && num[i][j] != num[i][j + 1]) {
				tmp = roomsize[num[i][j]] + roomsize[num[i][j + 1]];
				maxtworoom = tmp > maxtworoom ? tmp : maxtworoom;
			}
		}
	}
	cout << number << endl;
	cout << maxroomsize << endl; 
	cout << maxtworoom << endl;
	return 0;
}