#include <iostream>
using namespace std;
int n, m, v;
bool dver[1001], bver[1001];
bool line[1001][1001];
int que[1000], front = -1, back = -1;
void dfs(int s) {
    cout << s << " ";
    dver[s] = false;
    for (int i = 1; i < 1001; i++) {
        if (!line[s][i] || !dver[i]) continue;
        dfs(i);
    }
}
void push(int in) {
    back++;
    que[back] = in;
}
int pop() {
    front++;
    return que[front];
}
void bfs(int s) {
    push(s);
	bver[s] = false;
    while (front < back) {
        int q = pop();
        cout << q << " ";
        for (int i = 0; i < 1001; i++) {
            if (!line[q][i] || !bver[i]) continue;
            push(i);
			bver[i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> v;
    for (register int i = 0; i < 1001; i++) {
        dver[i] = bver[i] = false;
        for (register int j = 0; j < 1001; j++) {
            line[i][j] = false;
        }
    }
    for (register int i = 0; i < m; i++) {
        int l1, l2;
        cin >> l1 >> l2;
        dver[l1] = dver[l2] = true;
        bver[l1] = bver[l2] = true;
        line[l1][l2] = line[l2][l1] = true;
    }
    dfs(v);
    cout << endl;
    bfs(v);
    return 0;
}