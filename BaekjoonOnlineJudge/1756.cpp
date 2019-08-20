#include <iostream>
#include <vector>
using namespace std;

int oven[300000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int D, N;
    cin >> D >> N;
    for (int i = 0; i < D; i++) {
        cin >> oven[i];
    }
    int height = D;
    for (int i = 0; i < N; i++) {
        int tmp_height = -1;
        int pizza;
        cin >> pizza;
        if (height == -1) continue;
        while (tmp_height + 1 < height && oven[tmp_height + 1] >= pizza) {
            tmp_height++;
        }
        height = tmp_height;
    }
    cout << height + 1;
    return 0;
}