#include <iostream>
using namespace std;
int n, m, map[500][500];
int a[19][4][2] = {
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},  // 0
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},  // 1
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},  // 2
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},  // 3
    {{0, 0}, {1, 0}, {0, 1}, {0, 2}},  // 4
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},  // 5
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}},  // 6
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},  // 7
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},  // 8
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},  // 9
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},  // 10
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},  // 11
    {{1, 0}, {1, 1}, {0, 1}, {0, 2}},  // 12
    {{1, 0}, {2, 0}, {0, 1}, {1, 1}},  // 13
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},  // 14
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},  // 15
    {{1, 0}, {0, 1}, {1, 1}, {2, 1}},  // 16
    {{1, 0}, {1, 1}, {1, 2}, {0, 1}},  // 17
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},  // 18
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (register int i = 0; i < n; i++) {
        for (register int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    int max = -1;
    for (register int k = 0; k < 19; k++) {
        for (register int i = 0; i < n; i++) {
            for (register int j = 0; j < m; j++) {
                int tsum = 0;
                bool flag = false;
                for (register int p = 0; p < 4; p++) {
                    int tx = i + a[k][p][0];
                    int ty = j + a[k][p][1];
                    if (tx >= n || ty >= m) {
                        flag = true;
                        break;
                    }
                    tsum += map[tx][ty];
                }
                if (flag) continue;
                if (tsum > max) max = tsum;
            }
        }
    }
    cout << max;
    return 0;
}