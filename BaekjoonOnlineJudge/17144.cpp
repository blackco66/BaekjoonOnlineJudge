#include <iostream>
using namespace std;
int R, C, T;
int airR;
int dust[50][50];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
void diffusion() {
    int nextdust[50][50];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            nextdust[i][j] = 0;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (dust[i][j] == -1) continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int dirY = i + dy[k];
                int dirX = j + dx[k];
                if (dirY < 0 || dirY >= R || dirX < 0 || dirX >= C || dust[dirY][dirX] == -1) continue;
                cnt++;
                nextdust[dirY][dirX] += dust[i][j] / 5;
            }
            nextdust[i][j] += dust[i][j] - (dust[i][j] / 5) * cnt;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (dust[i][j] == -1) continue;
            dust[i][j] = nextdust[i][j];
        }
    }
}
void airclean() {
    // Top
    for (int i = 0; i < airR - 1; i++) {
        dust[airR - i - 1][0] = dust[airR - i - 2][0];
    }
    for (int i = 0; i < C - 1; i++) {
        dust[0][i] = dust[0][i + 1];
    }
    for (int i = 0; i < airR; i++) {
        dust[i][C - 1] = dust[i + 1][C - 1];
    }
    for (int i = 0; i < C - 2; i++) {
        dust[airR][C - i - 1] = dust[airR][C - i - 2];
    }
    // Bottom
    for (int i = 0; i < R - airR - 3; i++) {
        dust[airR + i + 2][0] = dust[airR + i + 3][0];
    }
    for (int i = 0; i < C - 1; i++) {
        dust[R - 1][i] = dust[R - 1][i + 1];
    }
    for (int i = 0; i < R - airR - 2; i++) {
        dust[R - 1 - i][C - 1] = dust[R - 2 - i][C - 1];
    }
    for (int i = 0; i < C - 2; i++) {
        dust[airR + 1][C - i - 1] = dust[airR + 1][C - i - 2];
    }
    dust[airR][1] = 0;
    dust[airR + 1][1] = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int tmp;
            cin >> tmp;
            dust[i][j] = tmp;
            if (tmp == -1) {
                airR = i;
                airR--;
            }
        }
    }
    for (int tt = 0; tt < T; tt++) {
        diffusion();
        airclean();
    }
    int total = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (dust[i][j] == -1) continue;
            total += dust[i][j];
        }
    }
    cout << total;
    return 0;
}