#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int map[100][100];
int num_cnt[101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r, c, k;
    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    int row = 3, col = 3;
    while (map[r - 1][c - 1] != k) {
        if (row >= col) {
            int next_col = 0;
            for (int i = 0; i < row; i++) {
                vector<pair<int, int>> pairs;
                memset(num_cnt, 0, sizeof(num_cnt));
                for (int j = 0; j < col; j++) {
                    num_cnt[map[i][j]]++;
                }
                for (int j = 1; j < 101; j++) {
                    if (num_cnt[j] == 0) continue;
                    pairs.push_back(make_pair(num_cnt[j], j));
                }
                sort(pairs.begin(), pairs.end());
                int size = pairs.size() > 50 ? 50 : pairs.size();
                for (int j = 0; j < 100; j++) {
                    map[i][j] = 0;
                }
                for (int j = 0; j < size; j++) {
                    map[i][2 * j] = pairs[j].second;
                    map[i][2 * j + 1] = pairs[j].first;
                }
                if (next_col < 2 * size) {
                    next_col = 2 * size;
                }
            }
            col = next_col;
        } else {
            int next_row = 0;
            for (int i = 0; i < col; i++) {
                vector<pair<int, int>> pairs;
                memset(num_cnt, 0, sizeof(num_cnt));
                for (int j = 0; j < row; j++) {
                    num_cnt[map[j][i]]++;
                }
                for (int j = 1; j < 101; j++) {
                    if (num_cnt[j] == 0) continue;
                    pairs.push_back(make_pair(num_cnt[j], j));
                }
                sort(pairs.begin(), pairs.end());
                int size = pairs.size() > 50 ? 50 : pairs.size();
                for (int j = 0; j < 100; j++) {
                    map[j][i] = 0;
                }
                for (int j = 0; j < size; j++) {
                    map[2 * j][i] = pairs[j].second;
                    map[2 * j + 1][i] = pairs[j].first;
                }
                if (next_row < 2 * size) {
                    next_row = 2 * size;
                }
            }
            row = next_row;
        }
        cnt++;
        if (cnt > 100) break;
    }
    if (cnt > 100)
        cout << -1;
    else
        cout << cnt;
    return 0;
}