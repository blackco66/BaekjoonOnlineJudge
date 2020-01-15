#include <iostream>
using namespace std;
int n, m;
int cnt = 0;
char d[500000][21], res[500000][21];
int cmp(char a[21], char b[21]) {
    for (int i = 0; i < 21; i++) {
        if (a[i] == '\0' && b[i] == '\0') return 0;
        if (a[i] == '\0' || a[i] < b[i]) return 1;
        if (b[i] == '\0' || a[i] > b[i]) return -1;
    }
}
void swap(int idx1, int idx2) {
    for (int i = 0; i < 21; i++) {
        char tmp = res[idx1][i];
        res[idx1][i] = res[idx2][i];
        res[idx2][i] = tmp;
    }
}
int partition(int begin, int end) {
    char pivot[21];
    for (int i = 0; i < 21; i++) {
        pivot[i] = res[begin][i];
    }
    int left = begin;
    int right = end + 1;
    while (left < right) {
        do {
            left++;
        } while (left <= end && cmp(res[left], pivot) == 1);
        do {
            right--;
        } while (right >= begin && cmp(res[right], pivot) == -1);
        if (left < right) {
            swap(left, right);
        }
    }
    swap(begin, right);
    return right;
}
void sort(int begin, int end) {
    while (begin < end) {
        int p = partition(begin, end);
        sort(begin, p - 1);
        sort(p + 1, end);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    char tt[2];
    cin.getline(tt, 1);
    for (int i = 0; i < n; i++) {
        cin.getline(d[i], 21);
    }
    char bb[21];
    for (int i = 0; i < m; i++) {
        cin.getline(bb, 21);
        for (int i = 0; i < n; i++) {
            if (cmp(bb, d[i]) == 0) {
                for (int j = 0; j < 21; j++) {
                    res[cnt][j] = bb[j];
                }
                cnt++;
            }
        }
    }
    sort(0, cnt - 1);
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < 21; j++) {
            if (res[i][j] == '\0') break;
            cout << res[i][j];
        }
        cout << '\n';
    }
    return 0;
}