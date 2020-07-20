#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    int alen = a.length();
    int blen = b.length();
    int llen = alen > blen ? alen : blen;
    vector<int> result(llen + 1);
    int next = 0;
    for (int i = 0; i < llen + 1; i++) {
        int cur = llen - i;
        int acur = alen - i - 1;
        int bcur = blen - i - 1;
        int sum = next;
        if (acur >= 0) {
            sum += a[acur] - '0';
        }
        if (bcur >= 0) {
            sum += b[bcur] - '0';
        }
        if (sum >= 10) {
            next = 1;
            sum -= 10;
        } else {
            next = 0;
        }
        result[cur] = sum;
    }
    if (result[0] != 0) {
        cout << result[0];
    }
    for (int i = 1; i < llen + 1; i++) {
        cout << result[i];
    }
    return 0;
}