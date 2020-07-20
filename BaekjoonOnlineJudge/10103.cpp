#include <iostream>
using namespace std;

int main() {
    int score0 = 100, score1 = 100;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            score1 -= b;
        } else if (b < a) {
            score0 -= a;
        }
    }
    cout << score0 << endl
         << score1;
    return 0;
}
