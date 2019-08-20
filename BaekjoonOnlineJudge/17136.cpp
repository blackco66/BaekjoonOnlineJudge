#include <iostream>
#include <vector>
using namespace std;

int paper[6] = {0, 5, 5, 5, 5, 5};
int ans = -1;
vector<vector<bool>> update(int r, int c, int len, vector<vector<bool>> board) {
    for (int i = r; i < r + len; i++) {
        for (int j = c; j < c + len; j++) {
            board[i][j] = !board[i][j];
        }
    }
    return board;
}
bool check(int r, int c, int len, vector<vector<bool>> board) {
    if (r + len > 10 || c + len > 10) return false;
    for (int i = r; i < r + len; i++) {
        for (int j = c; j < c + len; j++) {
            if (!board[i][j]) return false;
        }
    }
    return true;
}
void dfs(int r, int c, int cnt, vector<vector<bool>> board, int sum) {
    if (ans != -1 && cnt > ans) return;
    if (sum == 0) {
        ans = cnt;
    }
    bool flag = false;
    for (int i = r; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j]) {
                r = i;
                c = j;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    for (int len = 5; len > 0; len--) {
        if (paper[len] == 0) continue;
        if (check(r, c, len, board)) {
            board = update(r, c, len, board);
            paper[len]--;
            dfs(r, c, cnt + 1, board, sum - len * len);
            board = update(r, c, len, board);
            paper[len]++;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<bool>> board(10, vector<bool>(10, false));
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        int tmp;
        cin >> tmp;
        board[i / 10][i % 10] = tmp;
        sum += tmp;
    }
    dfs(0, 0, 0, board, sum);
    cout << ans;
    return 0;
}