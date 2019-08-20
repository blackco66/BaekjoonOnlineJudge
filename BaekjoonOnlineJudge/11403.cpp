#include <iostream>
#include <queue>
using namespace std;
int N;
int graph[100][100];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
		bool visited[100] = { false };
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int j = 0; j < N; j++) {
				if (graph[cur][j] && !visited[j]) {
					q.push(j);
					graph[i][j] = 1;
					visited[j] = true;
				}
			}
		}
		
    }
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}