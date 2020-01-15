#include <iostream>
using namespace std;
int ans[1001];
void dp(int num) {
    if (ans[num] != -1) return;
    if (ans[num - 1] == -1) dp(num - 1);
    if (ans[num - 2] == -1) dp(num - 2);
    ans[num] = (ans[num - 1] + ans[num - 2]) % 10007;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        ans[i] = -1;
    }
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    dp(n);
    cout << ans[n];
    return 0;
}