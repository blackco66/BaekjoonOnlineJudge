#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, m;
        cin >> n >> m;
        int diff[500] = {0};
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int first;
            cin >> first;
            for (int j = 0; j < m - 1; j++) {
                int second;
                cin >> second;
                if (!flag) continue;
                int tmpDiff = second - first;
                if (i == 0) diff[j] = tmpDiff;
                if (diff[j] < tmpDiff) {
                    flag = false;
                }
                diff[j] = tmpDiff;
                first = second;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}