#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void dfs(vector<vector<bool>>& graph, vector<bool>& group, int start, int n) {
    group[start] = true;
    for (int i = 0; i < n; i++) {
        if (graph[start][i] && !group[i]) {
            dfs(graph, group, i, n);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<bool> row(n, false);
    vector<vector<bool>> graph(n, row);
    vector<stack<int>> enemy(n);
    while (m--) {
        char FE;
        int p, q;
        cin >> FE >> p >> q;
        if (FE == 'F') {
            graph[p - 1][q - 1] = true;
            graph[q - 1][p - 1] = true;
        } else {
            enemy[p - 1].push(q);
            enemy[q - 1].push(p);
        }
    }
    for (int i = 0; i < n; i++) {
        if (enemy[i].size() > 1) {
            int p = enemy[i].top();
            enemy[i].pop();
            while (!enemy[i].empty()) {
                int q = enemy[i].top();
                enemy[i].pop();
                graph[p - 1][q - 1] = true;
                graph[q - 1][p - 1] = true;
            }
        }
    }
    vector<bool> group(n, false);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!group[i]) {
            cnt++;
            dfs(graph, group, i, n);
        }
    }
    cout << cnt;
    return 0;
}