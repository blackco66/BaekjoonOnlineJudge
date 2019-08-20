#include <iostream>
using namespace std;
int N, M, H;
bool check(bool* ladder) {
    bool flag = true;
    for (int i = 0; i < N - 1; i++) {
        int cur = i;
        for (int j = 0; j < H; j++) {
            int left = (cur - 1) * H + j;
            int right = cur * H + j;
            if (left >= 0 && ladder[left]) {
                cur--;
                continue;
            }
            if (right < (N - 1) * H && ladder[right]) {
                cur++;
                continue;
            }
        }
        if (cur != i) {
            flag = false;
            break;
        }
    }
    return flag;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> H;
    bool ladder[270] = {false};
    for (int i = 0; i < M; i++) {
        int horizontal, vertical;
        cin >> horizontal >> vertical;
        ladder[(vertical - 1) * H + (horizontal - 1)] = true;
    }
    bool flag = false;
    if (check(ladder)) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < (N - 1) * H; i++) {
        if (ladder[i]) continue;
        if (i - H >= 0 && ladder[i - H]) continue;
        if (i + H < (N - 1) * H && ladder[i + H]) continue;
        ladder[i] = true;
        if (check(ladder)) {
            cout << 1;
            return 0;
        }
        ladder[i] = false;
    }
    for (int i = 0; i < (N - 1) * H; i++) {
        if (ladder[i]) continue;
        if (i - H >= 0 && ladder[i - H]) continue;
        if (i + H < (N - 1) * H && ladder[i + H]) continue;
        ladder[i] = true;
        for (int j = i + 1; j < (N - 1) * H; j++) {
            if (ladder[j]) continue;
            if (j - H >= 0 && ladder[j - H]) continue;
            if (j + H < (N - 1) * H && ladder[j + H]) continue;
            ladder[j] = true;
            if (check(ladder)) {
                cout << 2;
                return 0;
            }
            ladder[j] = false;
        }
        ladder[i] = false;
    }
    for (int i = 0; i < (N - 1) * H; i++) {
        if (ladder[i]) continue;
        if (i - H >= 0 && ladder[i - H]) continue;
        if (i + H < (N - 1) * H && ladder[i + H]) continue;
        ladder[i] = true;
        for (int j = i + 1; j < (N - 1) * H; j++) {
            if (ladder[j]) continue;
            if (j - H >= 0 && ladder[j - H]) continue;
            if (j + H < (N - 1) * H && ladder[j + H]) continue;
            ladder[j] = true;
            for (int k = j + 1; k < (N - 1) * H; k++) {
                if (ladder[k]) continue;
                if (k - H >= 0 && ladder[k - H]) continue;
                if (k + H < (N - 1) * H && ladder[k + H]) continue;
                ladder[k] = true;
                if (check(ladder)) {
                    cout << 3;
                    return 0;
                }
                ladder[k] = false;
            }
            ladder[j] = false;
        }
        ladder[i] = false;
    }
    cout << -1;
    return 0;
}