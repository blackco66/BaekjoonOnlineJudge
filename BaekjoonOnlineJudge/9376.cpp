#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MIN = -2147483647;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int row, col;
        cin >> row >> col;
        vector<char> maze(row * col);
        int p1 = -1, p2 = -1;
        for (int i = 0; i < row * col; i++) {
            cin >> maze[i];
            if (maze[i] == '$') {
                if (p1 == -1)
                    p1 = i;
                else
                    p2 = i;
            }
        }
        vector<vector<int>> oneWall;
    }
    return 0;
}