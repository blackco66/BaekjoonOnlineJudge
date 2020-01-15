#include <iostream>
using namespace std;
int main() {
    long long a, b, v;
    cin >> a >> b >> v;
    if (v <= a) {
        cout << 1;
    } else if ((v - a) % (a - b) == 0) {
        cout << (v - a) / (a - b) + 1;
    } else {
        cout << (v - a) / (a - b) + 2;
    }
    return 0;
}