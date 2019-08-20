#include <iostream>
#include <vector>
using namespace std;
int maxheight;

int findLongest(vector<int> map, vector<bool> visited, int start, int len,
                const int N) {
    bool flagE = false;
    bool flagS = false;
    bool flagW = false;
    bool flagN = false;
    if (start % N == N - 1 ||
        (map[start + 1] >= map[start] || visited[start + 1])) {
        flagE = true;
    }
    if (start % N == 0 ||
        (map[start - 1] >= map[start] || visited[start - 1])) {
        flagW = true;
    }
    if (start / N == N - 1 ||
        (map[start + N] >= map[start] || visited[start + N])) {
        flagS = true;
    }
    if (start / N == 0 ||
        (map[start - N] >= map[start] || visited[start - N])) {
        flagN = true;
    }
    if (flagE && flagN && flagS && flagW) {
        return len;
    }
    int maxlen = -1;
    if (!flagE) {
        visited[start + 1] = true;
        int tmplen = findLongest(map, visited, start + 1, len + 1, N);
		visited[start + 1] = false;
        if (tmplen > maxlen) maxlen = tmplen;
    }
    if (!flagW) {
        visited[start - 1] = true;
        int tmplen = findLongest(map, visited, start - 1, len + 1, N);
		visited[start - 1] = false;
        if (tmplen > maxlen) maxlen = tmplen;
    }
    if (!flagS) {
        visited[start + N] = true;
        int tmplen = findLongest(map, visited, start + N, len + 1, N);
		visited[start + N] = false;
        if (tmplen > maxlen) maxlen = tmplen;
    }
    if (!flagN) {
        visited[start - N] = true;
        int tmplen = findLongest(map, visited, start - N, len + 1, N);
		visited[start - N] = false;
        if (tmplen > maxlen) maxlen = tmplen;
    }
    return maxlen;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int N, H;
        cin >> N >> H;
        vector<int> map(N * N);
        maxheight = -1;
        for (int i = 0; i < N * N; i++) {
            int tmp;
            cin >> tmp;
            map[i] = tmp;
            if (maxheight < tmp) maxheight = tmp;
        }
        int max = -1;
        for (int i = 0; i <= H; i++) {
            for (int j = 0; j < N * N; j++) {
                map[j] -= i;
                int tmp;
                for (int k = 0; k < N * N; k++) {
                    if (map[k] != maxheight) continue;
                    vector<bool> visited(N * N, false);
                    visited[k] = true;
                    tmp = findLongest(map, visited, k, 1, N);
                    if (max < tmp) max = tmp;
                }
                map[j] += i;
            }
        }
        cout << "#" << tt + 1 << " " << max << endl;
    }
    return 0;
}