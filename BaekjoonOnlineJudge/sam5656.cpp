#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int tt = 0; tt < T; tt++) {
        int N, W, H;
        cin >> N >> W >> H;
        int brick[15][12];
        int brickcnt = 200000;
        for (int i = H - 1; i >= 0; i--) {
            for (int j = 0; j < W; j++) {
                int tmp;
                cin >> tmp;
                brick[i][j] = tmp;
            }
        }
        int repeat = 1;
        for (int i = 0; i < N; i++) {
            repeat *= W;
        }
        for (int i = 0; i < repeat; i++) {
            int tmprepeat = i;
            int tmpbrick[15][12];
            for (int j = 0; j < 15; j++) {
                for (int k = 0; k < 12; k++) {
                    tmpbrick[j][k] = brick[j][k];
                    if (j >= H || k >= W) tmpbrick[j][k] = 0;
                }
            }
            for (int j = 0; j < N; j++) {
                int drop = tmprepeat % W;
                tmprepeat = (tmprepeat - drop) / W;
                int height = -1;
                for (int k = H - 1; k >= 0; k--) {
                    if (tmpbrick[k][drop] != 0) {
                        height = k;
                        break;
                    }
                }
                if (height == -1) continue;
                queue<int> q, qq;
                if (tmpbrick[height][drop] > 1) {
                    q.push(height * W + drop);
                    qq.push(tmpbrick[height][drop]);
                }
                tmpbrick[height][drop] = 0;
                while (!q.empty()) {
                    int next = q.front();
                    q.pop();
                    int num = qq.front();
                    qq.pop();
                    int tmph = next / W;
                    int tmpw = next % W;
                    for (int k = 1; k < num; k++) {
                        if (tmph - k < 0) break;
                        if (tmpbrick[tmph - k][tmpw] > 1) {
                            q.push((tmph - k) * W + tmpw);
                            qq.push(tmpbrick[tmph - k][tmpw]);
                        }
                        tmpbrick[tmph - k][tmpw] = 0;
                    }
                    for (int k = 1; k < num; k++) {
                        if (tmph + k >= H) break;
                        if (tmpbrick[tmph + k][tmpw] > 1) {
                            q.push((tmph + k) * W + tmpw);
                            qq.push(tmpbrick[tmph + k][tmpw]);
                        }
                        tmpbrick[tmph + k][tmpw] = 0;
                    }
                    for (int k = 1; k < num; k++) {
                        if (tmpw - k < 0) break;
                        if (tmpbrick[tmph][tmpw - k] > 1) {
                            q.push(tmph * W + tmpw - k);
                            qq.push(tmpbrick[tmph][tmpw - k]);
                        }
                        tmpbrick[tmph][tmpw - k] = 0;
                    }
                    for (int k = 1; k < num; k++) {
                        if (tmpw + k < 0) break;
                        if (tmpbrick[tmph][tmpw + k] > 1) {
                            q.push(tmph * W + tmpw + k);
                            qq.push(tmpbrick[tmph][tmpw + k]);
                        }
                        tmpbrick[tmph][tmpw + k] = 0;
                    }
                }
                for (int k = 0; k < W; k++) {
                    int tmpcol[15];
                    int colh = 0;
                    for (int l = 0; l < H; l++) {
                        if (tmpbrick[l][k] == 0) continue;
                        tmpcol[colh] = tmpbrick[l][k];
                        colh++;
                        tmpbrick[l][k] = 0;
                    }
                    for (int l = 0; l < colh; l++) {
                        tmpbrick[l][k] = tmpcol[l];
                    }
                }
            }
            int tmpcnt = 0;
            for (int j = 0; j < H; j++) {
                for (int k = 0; k < W; k++) {
                    if (tmpbrick[j][k] != 0) tmpcnt++;
                }
            }
            if (brickcnt > tmpcnt) brickcnt = tmpcnt;
        }
        cout << "#" << tt + 1 << " " << brickcnt << endl;
    }
    return 0;
}