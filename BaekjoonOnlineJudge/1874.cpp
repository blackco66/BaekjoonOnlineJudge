#include <iostream>
using namespace std;
int n, stack[100000], pos = -1, post = 1, cnt = 0;
char pp[200000];
bool push() {
    if (post > n) return false;
    pp[cnt++] = '+';
    stack[++pos] = post++;
    return true;
}
void pop() {
    if (pos < 0) return;
    pp[cnt++] = '-';
    stack[pos--] = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int input;
    int nn = n;
    while (nn--) {
        cin >> input;
        if (pos == -1) push();
        if (stack[pos] < input) {
            int tmp = post;
            for (int i = 0; i < input - tmp + 1; i++) {
                push();
            }
            pop();
        } else if (stack[pos] > input) {
            cout << "NO" << '\n';
            return 0;
        } else {
            pop();
        }
    }
    for (int i = 0; i < cnt; i++) {
        cout << pp[i] << '\n';
    }
    return 0;
}