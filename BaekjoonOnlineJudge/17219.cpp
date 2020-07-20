#include <iostream>
using namespace std;
int n, m;
char site[100000][21], pw[100000][21];
int cmp(char a[21], char b[21]) {
    for (int i = 0; i < 21; i++) {
        if (a[i] == '\0' && b[i] == '\0') return 0;
        if (a[i] == '\0' || a[i] < b[i]) return 1;
        if (b[i] == '\0' || a[i] > b[i]) return -1;
    }
    cout << "fn cmp error" << endl;
    return 100;
}
void swap(int idx1, int idx2) {
    if (idx1 == idx2) return;
    for (int i = 0; i < 21; i++) {
        char tchar = site[idx1][i];
        site[idx1][i] = site[idx2][i];
        site[idx2][i] = tchar;
        char tpw = pw[idx1][i];
        pw[idx1][i] = pw[idx2][i];
        pw[idx2][i] = tpw;
    }
}
int partition(int begin, int end) {
    char pivot[21];
    int piv = (begin * 2 + end) / 3;
    swap(begin, piv);
    for (int i = 0; i < 21; i++) {
        pivot[i] = site[begin][i];
    }
    int left = begin;
    int right = end + 1;
    while (left < right) {
        do {
            left++;
        } while (left <= end && cmp(site[left], pivot) == 1);
        do {
            right--;
        } while (right >= begin && cmp(site[right], pivot) == -1);
        if (left < right) {
            swap(left, right);
        }
    }
    swap(begin, right);
    return right;
}
void sort(int begin, int end) {
    if (begin < end) {
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
    for (register int i = 0; i < n; i++) {
        char tchar[42];
        cin.getline(tchar, 42);
        int tspace = 0;
        for (register int j = 0; j < 42; j++) {
            if (tchar[j] == '\0')
                break;
            else if (tchar[j] == ' ') {
                tspace = j;
                continue;
            }

            if (tspace == 0) {
                site[i][j] = tchar[j];
            } else {
                pw[i][j - tspace - 1] = tchar[j];
            }
        }
    }
    sort(0, n - 1);
    for (register int i = 0; i < m; i++) {
        char tchar[21];
        cin.getline(tchar, 21);
        int low = 0;
        int high = n - 1;
        int tcmp = 100;
        while (low <= high && tcmp != 0) {
            int mid = (low + high) / 2;
            tcmp = cmp(tchar, site[mid]);
            if (tcmp == 1) {
                high = mid - 1;
            } else if (tcmp == -1) {
                low = mid + 1;
            } else {
                for (register int j = 0; j < 21; j++) {
                    if (pw[mid][j] == '\0') break;
                    cout << pw[mid][j];
                }
                cout << '\n';
            }
        }
    }
    return 0;
}