#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int cnt = 0;
int result(vector<vector<int>> state, int inning) {
    int out = 0;
    bool cur[3] = {0, 0, 0};
    int score = 0;
    while (out != 3) {
        cnt = cnt % 9;
        if (state[cnt][inning] == 0) {
            out++;
        } else if (state[cnt][inning] == 1) {
            if (cur[2]) score++;
            cur[2] = cur[1];
            cur[1] = cur[0];
            cur[0] = true;
        } else if (state[cnt][inning] == 2) {
            if (cur[2]) score++;
            if (cur[1]) score++;
            cur[2] = cur[0];
            cur[1] = true;
            cur[0] = false;
        } else if (state[cnt][inning] == 3) {
            if (cur[2]) score++;
            if (cur[1]) score++;
            if (cur[0]) score++;
            cur[2] = true;
            cur[1] = false;
            cur[0] = false;
        } else if (state[cnt][inning] == 4) {
            if (cur[2]) score++;
            if (cur[1]) score++;
            if (cur[0]) score++;
            score++;
            cur[2] = false;
            cur[1] = false;
            cur[0] = false;
        }
		cnt++;
    }
    return score;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<int>> state(9, vector<int>(n));
    int max = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> state[j][i];
        }
    }
    int lineup[9];
    vector<vector<int>> current(9, vector<int>(n));
    current[3] = state[0];
    for (int a0 = 1; a0 < 9; a0++) {
        current[0] = state[a0];
        for (int a1 = 1; a1 < 9; a1++) {
            if (a1 == a0) continue;
            current[1] = state[a1];
            for (int a2 = 1; a2 < 9; a2++) {
                if (a2 == a1 || a2 == a0) continue;
                current[2] = state[a2];
                for (int a4 = 1; a4 < 9; a4++) {
                    if (a4 == a2 || a4 == a1 || a4 == a0) continue;
                    current[4] = state[a4];
                    for (int a5 = 1; a5 < 9; a5++) {
                        if (a5 == a4 || a5 == a2 || a5 == a1 || a5 == a0)
                            continue;
                        current[5] = state[a5];
                        for (int a6 = 1; a6 < 9; a6++) {
                            if (a6 == a5 || a6 == a4 || a6 == a2 ||
                                a6 == a1 || a6 == a0)
                                continue;
                            current[6] = state[a6];
                            for (int a7 = 1; a7 < 9; a7++) {
                                if (a7 == a6 || a7 == a5 || a7 == a4 ||
                                    a7 == a2 || a7 == a1 || a7 == a0)
                                    continue;
                                current[7] = state[a7];
                                for (int a8 = 1; a8 < 9; a8++) {
                                    if (a8 == a7 || a8 == a6 || a8 == a5 ||
                                        a8 == a4 || a8 == a2 ||
                                        a8 == a1 || a8 == a0)
                                        continue;
                                    current[8] = state[a8];
                                    int tmp_score = 0;
									cnt = 0;
                                    for (int i = 0; i < n; i++) {
                                        tmp_score = result(current, i);
                                    }
                                    if (tmp_score > max) max = tmp_score;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << max;
    return 0;
}