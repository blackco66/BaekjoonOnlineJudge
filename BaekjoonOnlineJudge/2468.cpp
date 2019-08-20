#include <iostream>
#include <queue>
using namespace std;
int map[10000];
bool boolmap[10000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int max = -1;
    int min = 101;
    for (int i = 0; i < n * n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > max) max = tmp;
        if (tmp < min) min = tmp;
		map[i] = tmp;
    }
    int maxArea = 1;
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < n * n; j++) {
            boolmap[j] = (map[j] > i);
        }
        int tmpArea = 0;
        for (int j = 0; j < n * n; j++) {
            if (!boolmap[j]) continue;
            queue<int> q;
            q.push(j);
            boolmap[j] = false;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (cur / n != 0 && boolmap[cur - n]) {
                    q.push(cur - n);
                    boolmap[cur - n] = false;
                }
                if (cur / n != n - 1 && boolmap[cur + n]) {
                    q.push(cur + n);
                    boolmap[cur + n] = false;
                }
                if (cur % n != 0 && boolmap[cur - 1]) {
                    q.push(cur - 1);
                    boolmap[cur - 1] = false;
                }
                if (cur % n != n - 1 && boolmap[cur + 1]) {
                    q.push(cur + 1);
                    boolmap[cur + 1] = false;
                }
            }
            tmpArea++;
        }
        if (tmpArea > maxArea) maxArea = tmpArea;
    }
    cout << maxArea;
    return 0;
}