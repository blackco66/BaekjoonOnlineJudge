#include <iostream>
using namespace std;

void group(const int cur[], bool tmp[], int curr, int i) {
    tmp[i] = true;
    if (i == 0) {
        if (curr == cur[1] && !tmp[1]) {
            group(cur, tmp, curr, 1);
        }
        if (curr == cur[6] && !tmp[6]) {
            group(cur, tmp, curr, 6);
        }
    } else if (i == 66) {
        if (curr == cur[60] && !tmp[60]) {
            group(cur, tmp, curr, 60);
        }
        if (curr == cur[67] && !tmp[67]) {
            group(cur, tmp, curr, 67);
        }
    } else if (i == 5) {
        if (curr == cur[4] && !tmp[4]) {
            group(cur, tmp, curr, 4);
        }
        if (curr == cur[11] && !tmp[11]) {
            group(cur, tmp, curr, 11);
        }
    } else if (i == 71) {
        if (curr == cur[70] && !tmp[70]) {
            group(cur, tmp, curr, 70);
        }
        if (curr == cur[65] && !tmp[65]) {
            group(cur, tmp, curr, 65);
        }
    } else if (i < 5) {
        if (curr == cur[i - 1] && !tmp[i - 1]) {
            group(cur, tmp, curr, i - 1);
        }
        if (curr == cur[i + 1] && !tmp[i + 1]) {
            group(cur, tmp, curr, i + 1);
        }
        if (curr == cur[i + 6] && !tmp[i + 6]) {
            group(cur, tmp, curr, i + 6);
        }
    } else if (i % 6 == 0) {
        if (curr == cur[i - 6] && !tmp[i - 6]) {
            group(cur, tmp, curr, i - 6);
        }
        if (curr == cur[i + 6] && !tmp[i + 6]) {
            group(cur, tmp, curr, i + 6);
        }
        if (curr == cur[i + 1] && !tmp[i + 1]) {
            group(cur, tmp, curr, i + 1);
        }
    } else if (i % 6 == 5) {
        if (curr == cur[i - 6] && !tmp[i - 6]) {
            group(cur, tmp, curr, i - 6);
        }
        if (curr == cur[i + 6] && !tmp[i + 6]) {
            group(cur, tmp, curr, i + 6);
        }
        if (curr == cur[i - 1] && !tmp[i - 1]) {
            group(cur, tmp, curr, i - 1);
        }
    } else if (66 < i && i < 71) {
        if (curr == cur[i - 1] && !tmp[i - 1]) {
            group(cur, tmp, curr, i - 1);
        }
        if (curr == cur[i + 1] && !tmp[i + 1]) {
            group(cur, tmp, curr, i + 1);
        }
        if (curr == cur[i - 6] && !tmp[i - 6]) {
            group(cur, tmp, curr, i - 6);
        }
    } else {
        if (curr == cur[i - 1] && !tmp[i - 1]) {
            group(cur, tmp, curr, i - 1);
        }
        if (curr == cur[i + 1] && !tmp[i + 1]) {
            group(cur, tmp, curr, i + 1);
        }
        if (curr == cur[i - 6] && !tmp[i - 6]) {
            group(cur, tmp, curr, i - 6);
        }
        if (curr == cur[i + 6] && !tmp[i + 6]) {
            group(cur, tmp, curr, i + 6);
        }
    }
}
bool eliminate(int cur[]) {
    bool flag = false;
    bool grouped[72] = {false};
    for (int i = 0; i < 71; i++) {
        int curr = cur[i];
        if (grouped[i] || curr == 0) {
            continue;
        }
        int cnt = 0;
        bool tmp[72] = {false};
        group(cur, tmp, curr, i);

        for (int j = i; j < 72; j++) {
            if (tmp[j]) {
                cnt++;
            }
        }
        if (cnt > 3) {
            flag = true;
            for (int j = i; j < 72; j++) {
                if (tmp[j]) {
                    grouped[j] = true;
                }
            }
        }
    }
    if (!flag) {
        return flag;
    }
    int post[72] = {0};
    for (int i = 0; i < 6; i++) {
        int line = 11;
        for (int j = 11; j >= 0; j--) {
            int pos = i + j * 6;
            if (!grouped[pos]) {
                post[i + line * 6] = cur[pos];
                line--;
            }
        }
    }
    for (int i = 0; i < 72; i++) {
        cur[i] = post[i];
    }
    /*for (int i = 0; i < 12; i++) {
        cout << post[i * 6] << post[i * 6 + 1] << post[i * 6 + 2]
             << post[i * 6 + 3] << post[i * 6 + 4] << post[i * 6 + 5] << endl;
    }
    cout << "------------" << endl;*/
    return flag;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cur[72] = {0};
    for (int i = 0; i < 72; i++) {
        char c;
        cin >> c;
        switch (c) {
            case 'R':
                cur[i] = 1;
                break;
            case 'G':
                cur[i] = 2;
                break;
            case 'B':
                cur[i] = 3;
                break;
            case 'P':
                cur[i] = 4;
                break;
            case 'Y':
                cur[i] = 5;
                break;
            default:
                break;
        }
    }
    int cnt = 0;
    /*for (int i = 0; i < 12; i++) {
        cout << cur[i * 6] << cur[i * 6 + 1] << cur[i * 6 + 2] << cur[i * 6 + 3]
             << cur[i * 6 + 4] << cur[i * 6 + 5] << endl;
    }
    cout << "------------" << endl;*/
    while (1) {
        if (eliminate(cur)) {
            cnt++;
        } else {
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}