#include <iostream>
#include <queue>
using namespace std;
int pop[50][50];  // population
bool visited[50][50];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int N, L, R;
bool move() {
    bool ismoved = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            queue<int> q;
            queue<int> store;
            int total = 0;
            q.push(i * N + j);
            store.push(i * N + j);
            visited[i][j] = true;
            total += pop[i][j];
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                int curY = cur / N;
                int curX = cur % N;
                for (int dir = 0; dir < 4; dir++) {
                    int ny = curY + dy[dir];
                    int nx = curX + dx[dir];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                    if (visited[ny][nx]) continue;
                    int diff = pop[curY][curX] - pop[ny][nx];
                    diff = diff > 0 ? diff : -diff;
                    if (diff < L || diff > R) continue;
                    q.push(ny * N + nx);
                    store.push(ny * N + nx);
                    visited[ny][nx] = true;
                    total += pop[ny][nx];
                }
            }
            if (store.size() == 1) continue;
            ismoved = true;
            int average = total / store.size();
            while (!store.empty()) {
                int cur = store.front();
                store.pop();
                pop[cur / N][cur % N] = average;
            }
        }
    }
    return ismoved;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> pop[i][j];
        }
    }
    int cnt = 0;
    while (1) {
        if (!move()) break;
        cnt++;
    }
    cout << cnt;
    return 0;
}