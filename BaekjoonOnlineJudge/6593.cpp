#include <iostream>
#include <queue>
using namespace std;
int len[27000];
char map[27000];
bool visited[27000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		int L, R, C;
		cin >> L >> R >> C;
		int s, e;
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 0; i < L * R * C; i++) {
			char tmp;
			cin >> tmp;
			if (tmp == 'S') s = i;
			if (tmp == 'E') {
				e = i;
				tmp = '.';
			}
			map[i] = tmp;
		}
		for (int i = 0; i < 27000; i++) {
			len[i] = -1;
			visited[i] = false;
		}
		len[s] = 0;
		queue<int> q;
		q.push(s);
		visited[s] = true;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur / (R * C) != 0 && len[cur - (R * C)] == -1 && map[cur - (R * C)] == '.' && !visited[cur - (R * C)]) {
				q.push(cur - (R * C));
				visited[cur - (R * C)] = true;
			}
			if (cur / (R * C) != L - 1 && len[cur + (R * C)] == -1 && map[cur + (R * C)] == '.' && !visited[cur + (R * C)]) {
				q.push(cur + (R * C));
				visited[cur + (R * C)] = true;
			}
			if (cur % (R * C) / C != 0 && len[cur - C] == -1 && map[cur - C] == '.' && !visited[cur - C]) {
				q.push(cur - C);
				visited[cur - C] = true;
			}
			if (cur % (R * C) / C != C - 1 && len[cur + C] == -1 && map[cur + C] == '.' && !visited[cur + C]) {
				q.push(cur + C);
				visited[cur + C] = true;
			}
			if (cur % (R * C) % C != 0 && len[cur - 1] == -1 && map[cur - 1] == '.' && !visited[cur - 1]) {
				q.push(cur - 1);
				visited[cur - 1] = true;
			}
			if (cur % (R * C) % C != C - 1 && len[cur + 1] == -1 && map[cur + 1] == '.' && !visited[cur + 1]) {
				q.push(cur + 1);
				visited[cur + 1] = true;
			}
			if (cur == s) continue;
			int min = 30000;
			if (cur / (R * C) != 0 && len[cur - (R * C)] != -1 && min > len[cur - (R * C)]) {
				min = len[cur - (R * C)];
			}
			if (cur / (R * C) != L - 1 && len[cur + (R * C)] != -1 && min > len[cur + (R * C)]) {
				min = len[cur + (R * C)];
			}
			if (cur % (R * C) / C != 0 && len[cur - C] != -1 && min > len[cur - C]) {
				min = len[cur - C];
			}
			if (cur % (R * C) / C != C - 1 && len[cur + C] != -1 && min > len[cur + C]) {
				min = len[cur + C];
			}
			if (cur % (R * C) % C != 0 && len[cur - 1] != -1 && min > len[cur - 1]) {
				min = len[cur - 1];
			}
			if (cur % (R * C) % C != C - 1 && len[cur + 1] != -1 && min > len[cur + 1]) {
				min = len[cur + 1];
			}
			len[cur] = min + 1;
			if (cur == e) break;
		}
		if (len[e] == -1) cout << "Trapped!" << endl;
		else cout << "Escaped in " << len[e] << " minute(s)." << endl;
	}

	return 0;
}