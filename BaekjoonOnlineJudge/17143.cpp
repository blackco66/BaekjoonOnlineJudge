#include <iostream>
#include <vector>
using namespace std;
int R, C;
struct shark {
    int s = 0, d = 1, z = 0;
    int ir = 0, ic = 1;
    shark(int rr, int cc, int ss, int dd, int zz) : ir(rr), ic(cc), s(ss), d(dd), z(zz) {}
    shark() {
        s = 0, d = 1, z = 0, ir = 0, ic = 1;
    }
};
shark map[100][100];
void update(int cnt) {
    vector<vector<shark>> nextmap(R * C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j].z == 0) continue;
            shark tmps = map[i][j];
            int totalmove = tmps.s * cnt;
            int nextr = 0, nextc = 0;
            if (tmps.d == 1) {
                nextc = tmps.ic;
                if (totalmove <= tmps.ir) {
                    nextr = tmps.ir - totalmove;
                } else {
                    int diff = totalmove - tmps.ir - 1;
                    if ((diff / (R - 1)) % 2 == 0) {
                        nextr = diff % (R - 1) + 1;
                    } else {
                        nextr = R - diff % (R - 1) - 2;
                    }
                }
            } else if (tmps.d == 2) {
                nextc = tmps.ic;
                if (totalmove <= R - tmps.ir - 1) {
                    nextr = tmps.ir + totalmove;
                } else {
                    int diff = totalmove - (R - tmps.ir);
                    if ((diff / (R - 1)) % 2 == 0) {
                        nextr = R - diff % (R - 1) - 2;
                    } else {
                        nextr = diff % (R - 1) + 1;
                    }
                }
            } else if (tmps.d == 3) {
                nextr = tmps.ir;
                if (totalmove <= C - tmps.ic - 1) {
                    nextc = tmps.ic + totalmove;
                } else {
                    int diff = totalmove - (C - tmps.ic);
                    if ((diff / (C - 1)) % 2 == 0) {
                        nextc = C - diff % (C - 1) - 2;
                    } else {
                        nextc = diff % (C - 1) + 1;
                    }
                }
            } else if (tmps.d == 4) {
                nextr = tmps.ir;
                if (totalmove <= tmps.ic) {
                    nextc = tmps.ic - totalmove;
                } else {
                    int diff = totalmove - tmps.ic - 1;
                    if ((diff / (C - 1)) % 2 == 0) {
                        nextc = diff % (C - 1) + 1;
                    } else {
                        nextc = C - diff % (C - 1) - 2;
                    }
                }
            }
            nextmap[nextr + nextc * R].push_back(tmps);
        }
    }

    for (int i = 0; i < R * C; i++) {
        shark init;
        map[i % R][i / R] = init;
        if (nextmap[i].size() < 1) continue;
        shark max = nextmap[i][0];
        for (int j = 1; j < nextmap[i].size(); j++) {
            if (max.z < nextmap[i][j].z) max = nextmap[i][j];
        }
        map[i % R][i / R] = max;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M;
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        int tr, tc, ts, td, tz;
        cin >> tr >> tc >> ts >> td >> tz;
        tr--;
        tc--;
        shark tmpshark(tr, tc, ts, td, tz);
        map[tr][tc] = tmpshark;
    }
    int total = 0;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            if (map[j][i].z == 0) continue;
            total += map[j][i].z;
            map[j][i].z = 0;
            break;
        }
        update(i + 1);
    }
    cout << total;

    return 0;
}