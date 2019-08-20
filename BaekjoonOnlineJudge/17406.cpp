#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX 2147483647
int A[50][50];
int B[50][50];
int N, M, K;
struct rotation {
    int r = 0, c = 0, s = 0;
	rotation() {}
	rotation(int rr, int cc, int ss) : r(rr), c(cc), s(ss) {}
};
void rotate(rotation cur) {
    for (int i = 1; i <= cur.s; i++) {
        int tmp = B[cur.r - i][cur.c - i];
        for (int j = 0; j < i * 2; j++) {
            B[cur.r - i + j][cur.c - i] = B[cur.r - i + j + 1][cur.c - i];
        }
        for (int j = 0; j < i * 2; j++) {
            B[cur.r + i][cur.c - i + j] = B[cur.r + i][cur.c - i + j + 1];
        }
        for (int j = 0; j < i * 2; j++) {
            B[cur.r + i - j][cur.c + i] = B[cur.r + i - j - 1][cur.c + i];
        }
        for (int j = 0; j < i * 2 - 1; j++) {
            B[cur.r - i][cur.c + i - j] = B[cur.r - i][cur.c + i - j - 1];
        }
		B[cur.r - i][cur.c - i + 1] = tmp;
    }
}
int findValue() {
    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        int tmp = 0;
        for (int j = 0; j < M; j++) {
            tmp += B[i][j];
        }
        if (tmp < min) min = tmp;
    }
    return min;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    vector<rotation> rotInfo(K);
    vector<int> permute(K);
    for (int i = 0; i < K; i++) {
        int tmpR, tmpC, tmpS;
        cin >> tmpR >> tmpC >> tmpS;
        rotation tmp(tmpR - 1, tmpC - 1, tmpS);
        rotInfo[i] = tmp;
        permute[i] = i;
    }
    int minValue = INT_MAX;
    do {		
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                B[i][j] = A[i][j];
            }
        }
        for (int i = 0; i < K; i++) {
            rotation cur = rotInfo[permute[i]];
            rotate(cur);
        }
        int tmpValue = findValue();
        if (tmpValue < minValue) minValue = tmpValue;
    } while (next_permutation(permute.begin(), permute.end()));
	cout << minValue << endl;
    return 0;
}