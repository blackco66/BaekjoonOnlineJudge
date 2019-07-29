#include <iostream>
#include <vector>
using namespace std;

bool vaildCheck(vector<int> rain, int cloud, int day,
                const vector<vector<bool>> event, const int N) {
    if (event[day][cloud]) {
        return false;
    }
    if (rain[0] > 6 || rain[1] > 6 || rain[2] > 6 || rain[3] > 6) {
        return false;
    }
    if (day == N - 1) {
        return true;
    }
    bool flag = false;
    day++;
    if (cloud == 0) {
        rain[0] = 0;
        rain[1]++;
        rain[2]++;
        rain[3]++;
        flag = vaildCheck(rain, 0, day, event, N) ||
               vaildCheck(rain, 1, day, event, N) ||
               vaildCheck(rain, 2, day, event, N) ||
               vaildCheck(rain, 3, day, event, N) ||
               vaildCheck(rain, 6, day, event, N);
        if (flag) return true;
    } else if (cloud == 1) {
        rain[0]++;
        rain[1]++;
        rain[2]++;
        rain[3]++;
        flag = vaildCheck(rain, 0, day, event, N) ||
               vaildCheck(rain, 1, day, event, N) ||
               vaildCheck(rain, 2, day, event, N) ||
               vaildCheck(rain, 4, day, event, N) ||
               vaildCheck(rain, 7, day, event, N);
        if (flag) return true;
    } else if (cloud == 2) {
        rain[0]++;
        rain[1] = 0;
        rain[2]++;
        rain[3]++;
        flag = vaildCheck(rain, 0, day, event, N) ||
               vaildCheck(rain, 1, day, event, N) ||
               vaildCheck(rain, 2, day, event, N) ||
               vaildCheck(rain, 5, day, event, N) ||
               vaildCheck(rain, 8, day, event, N);
        if (flag) return true;
    } else if (cloud == 3) {
        rain[0]++;
        rain[1]++;
        rain[2]++;
        rain[3]++;
        flag = vaildCheck(rain, 0, day, event, N) ||
               vaildCheck(rain, 3, day, event, N) ||
               vaildCheck(rain, 6, day, event, N) ||
               vaildCheck(rain, 4, day, event, N) ||
               vaildCheck(rain, 5, day, event, N);
        if (flag) return true;
    } else if (cloud == 4) {
        rain[0]++;
        rain[1]++;
        rain[2]++;
        rain[3]++;
        flag = vaildCheck(rain, 1, day, event, N) ||
               vaildCheck(rain, 3, day, event, N) ||
               vaildCheck(rain, 4, day, event, N) ||
               vaildCheck(rain, 5, day, event, N) ||
               vaildCheck(rain, 7, day, event, N);
        if (flag) return true;
    } else if (cloud == 5) {
        rain[0]++;
        rain[1]++;
        rain[2]++;
        rain[3]++;
        flag = vaildCheck(rain, 2, day, event, N) ||
               vaildCheck(rain, 3, day, event, N) ||
               vaildCheck(rain, 4, day, event, N) ||
               vaildCheck(rain, 5, day, event, N) ||
               vaildCheck(rain, 8, day, event, N);
        if (flag) return true;
    } else if (cloud == 6) {
        rain[0]++;
        rain[1]++;
        rain[2] = 0;
        rain[3]++;
        flag = vaildCheck(rain, 0, day, event, N) ||
               vaildCheck(rain, 3, day, event, N) ||
               vaildCheck(rain, 6, day, event, N) ||
               vaildCheck(rain, 7, day, event, N) ||
               vaildCheck(rain, 8, day, event, N);
        if (flag) return true;
    } else if (cloud == 7) {
        rain[0]++;
        rain[1]++;
        rain[2]++;
        rain[3]++;
        flag = vaildCheck(rain, 1, day, event, N) ||
               vaildCheck(rain, 4, day, event, N) ||
               vaildCheck(rain, 6, day, event, N) ||
               vaildCheck(rain, 7, day, event, N) ||
               vaildCheck(rain, 8, day, event, N);
        if (flag) return true;
    } else if (cloud == 8) {
        rain[0]++;
        rain[1]++;
        rain[2]++;
        rain[3] = 0;
        flag = vaildCheck(rain, 2, day, event, N) ||
               vaildCheck(rain, 5, day, event, N) ||
               vaildCheck(rain, 6, day, event, N) ||
               vaildCheck(rain, 7, day, event, N) ||
               vaildCheck(rain, 8, day, event, N);
        if (flag) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1) {
        int N;
        cin >> N;
        if (N == 0) break;
        vector<vector<bool>> event(N, vector<bool>(9));
        for (int i = 0; i < N; i++) {
            vector<bool> tmp(16);
            for (int j = 0; j < 16; j++) {
                bool e;
                cin >> e;
                tmp[j] = e;
            }
            event[i][0] = (tmp[0] || tmp[1] || tmp[4] || tmp[5]);
            event[i][1] = (tmp[1] || tmp[2] || tmp[5] || tmp[6]);
            event[i][2] = (tmp[2] || tmp[3] || tmp[6] || tmp[7]);
            event[i][3] = (tmp[4] || tmp[5] || tmp[8] || tmp[9]);
            event[i][4] = (tmp[5] || tmp[6] || tmp[9] || tmp[10]);
            event[i][5] = (tmp[6] || tmp[7] || tmp[10] || tmp[11]);
            event[i][6] = (tmp[8] || tmp[9] || tmp[12] || tmp[13]);
            event[i][7] = (tmp[9] || tmp[10] || tmp[13] || tmp[14]);
            event[i][8] = (tmp[10] || tmp[11] || tmp[14] || tmp[15]);
        }
        vector<int> rain(4, 1);
        int cloud = 4;  // 0 ~ 8
        bool valid = vaildCheck(rain, cloud, 0, event, N);
        cout << valid << endl;
    }
    return 0;
}