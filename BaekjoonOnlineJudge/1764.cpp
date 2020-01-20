#include <iostream>
using namespace std;
int n, m;
int cnt = 0;
char d[500000][21];
bool counting[50000];
int cmp(char a[21], char b[21]) {
    for (int i = 0; i < 21; i++) {
        if (a[i] == '\0' && b[i] == '\0') return 0;
        if (a[i] == '\0' || a[i] < b[i]) return 1;
        if (b[i] == '\0' || a[i] > b[i]) return -1;
    }
    cout << "fn cmp error" << endl;
    return 100;
}
void swap(char list[][21], int idx1, int idx2) {
    if (idx1 == idx2) return;
    for (int i = 0; i < 21; i++) {
        char tmp = list[idx1][i];
        list[idx1][i] = list[idx2][i];
        list[idx2][i] = tmp;
    }
}
int partition(char list[][21], int begin, int end) {
    char pivot[21];
    int piv = (begin * 2 + end) / 3;
    swap(list, piv, begin);
    for (int i = 0; i < 21; i++) {
        pivot[i] = list[begin][i];
    }
    int left = begin;
    int right = end + 1;
    while (left < right) {
        do {
            left++;
        } while (left <= end && cmp(list[left], pivot) == 1);
        do {
            right--;
        } while (right >= begin && cmp(list[right], pivot) == -1);
        if (left < right) {
            swap(list, left, right);
        }
    }
    swap(list, begin, right);
    return right;
}
void sort(char list[][21], int begin, int end) {
    if (begin < end) {
        int p = partition(list, begin, end);
        sort(list, begin, p - 1);
        sort(list, p + 1, end);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    char tt[2];
    cin.getline(tt, 1);
    for (register int i = 0; i < n; i++) {
        cin.getline(d[i], 21);
    }
    sort(d, 0, n - 1);
    char bb[21];
    bool flag = counting[0];
    for (register int i = 0; i < m; i++) {
        cin.getline(bb, 21);
        int low = 0;
        int high = n - 1;
        int tcmp = 100;
        while (low <= high && tcmp != 0) {
            int mid = (low + high) / 2;
            tcmp = cmp(bb, d[mid]);
            if (tcmp == 1) {
                high = mid - 1;
            } else if (tcmp == -1) {
                low = mid + 1;
            } else {
                counting[mid] = !flag;
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    for (register int i = 0; i < 50000; i++) {
        if (counting[i] == flag) continue;
        for (register int j = 0; j < 21; j++) {
            if (d[i][j] == '\0') break;
            cout << d[i][j];
        }
        cout << '\n';
    }
    return 0;
}