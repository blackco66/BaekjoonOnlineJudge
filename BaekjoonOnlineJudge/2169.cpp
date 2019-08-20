#include <iostream>
#include <vector>
using namespace std;
const int MIN = -2147483647;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int row, col;
    cin >> row >> col;
    vector<int> cost(row * col);
    for (int i = 0; i < row * col; i++) {
        cin >> cost[i];
    }
    vector<int> line(col, 0);
    line[0] = cost[0];
    for (int j = 1; j < col; j++) {
        line[j] = cost[j] + line[j - 1];
    }
    for (int i = 1; i < row; i++) {
		vector<int> tmp_line(col);
        for (int j = 0; j < col; j++) {
            int tmp_max = MIN;
            int tmp_sum = 0;
            for (int k = j; k >= 0; k--) {
                tmp_sum += cost[i * col + k];
                if (tmp_max < tmp_sum + line[k]) tmp_max = tmp_sum + line[k];
            }
            tmp_sum = cost[i * col + j];
            for (int k = j + 1; k < col; k++) {
                tmp_sum += cost[i * col + k];
                if (tmp_max < tmp_sum + line[k]) tmp_max = tmp_sum + line[k];
            }
			tmp_line[j] = tmp_max;
        }
		line = tmp_line;
    }
    cout << line[col - 1];
    return 0;
}