#include <iostream>
using namespace std;

struct couple {
    int first;
    int second;
    couple() {}
    couple(int f, int s) : first(f), second(s) {}
};
couple coordinate[102];
bool visited[102];
void visit_cu(int start, int n) {
    visited[start] = true;
    for (int i = 0; i < n + 2; i++) {
        if (visited[n + 1]) return;
        int dist1 = coordinate[start].first - coordinate[i].first;
        int dist2 = coordinate[start].second - coordinate[i].second;
        dist1 = dist1 > 0 ? dist1 : -dist1;
        dist2 = dist2 > 0 ? dist2 : -dist2;
        int dist = dist1 + dist2;
        if (dist <= 1000 && !visited[i]) {
            visit_cu(i, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n + 2; i++) {
            visited[i] = false;
        }
        for (int i = 0; i < n + 2; i++) {
            int a, b;
            cin >> a >> b;
            coordinate[i] = couple(a, b);
        }
        visit_cu(0, n);
        if (visited[n + 1]) {
            cout << "happy" << endl;
        } else {
            cout << "sad" << endl;
        }
    }
}