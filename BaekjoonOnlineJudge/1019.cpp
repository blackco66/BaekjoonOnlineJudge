#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long N;
    cin >> N;
    int num[10];
    memset(num, 0, sizeof(num));

    int comp = 1;
    int exp = 0;
    while (N / 10 / comp != 0) {
        comp *= 10;
        exp += 1;
    }
    int k = N / comp;
    int sum0 = exp + 1;
    int nine = 9;
    while (exp != 0) {
        sum0 += exp * nine;
        nine *= 10;
        exp -= 1;
    }
    num[0] = -sum0;

    while (N != 0) {
        comp = 1;
        exp = 0;
        while (N / 10 / comp != 0) {
            comp *= 10;
            exp += 1;
        }
        k = N / comp;
        for (int i = 0; i < k; i++) {
            num[i] += comp;
        }
        for (int i = 0; i < 10; i++) {
            num[i] += k * comp * exp / 10;
        }
        num[k] += N - k * comp + 1;
        int nextN = N - k * comp;
        int nextcomp = 1;
        int nextexp = 0;
        while (nextN / 10 / nextcomp != 0) {
            nextcomp *= 10;
            nextexp += 1;
        }
        if (nextN == 0) {
            nextexp = -1;
        }
        num[0] += (exp - nextexp - 1) * (nextN + 1);
        N = nextN;
    }

    for (int i = 0; i <= 9; i++) {
        cout << num[i] << " ";
    }
    return 0;
}