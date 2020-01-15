#include <iostream>
using namespace std;
int p[26];
int main() {
    for (int i = 0; i < 26; i++) {
        p[i] = -1;
    }
    int place = -1;
    char c;
    cin >> c;
    while (!cin.eof()) {
        place++;
        if (p[c - 'a'] == -1) {
            p[c - 'a'] = place;
        }
        cin >> c;
    }
    for (int i = 0; i < 26; i++) {
        cout << p[i] << " ";
    }
    return 0;
}