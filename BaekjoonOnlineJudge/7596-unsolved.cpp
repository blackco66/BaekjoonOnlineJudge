#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int M, N, H;
int tot = 0;
int ripe = 0;
int conv(int i, int j, int k) {
    return i + M * j + M * N * k;
    /*if (out < 0 || out > M * N * H - 1) {
        cout << "error!!!!";
        return 1;
    } else {
        return out;
    }*/
}

int search(int pos, int depth, vector<int> box, vector<bool> visited){
    int x = pos % M;
    int y = ((pos - x) % (M * N)) / M;
    int z = (pos - (x + M * y)) / (M * N);
    bool flag = (x > 0 && box[conv(x - 1, y, z)] == 1) ||
                (y > 0 && box[conv(x, y - 1, z)] == 1) ||
                (z > 0 && box[conv(x, y, z - 1)] == 1) ||
                (x < M - 1 && box[conv(x + 1, y, z)] == 1) ||
                (y < N - 1 && box[conv(x, y + 1, z)] == 1) ||
                (z < H - 1 && box[conv(x, y, z + 1)] == 1);
    if(flag){
        return depth + 1;
    }
    int min = INT_MAX;
    if (x > 0 && box[conv(x - 1, y, z)] == 0 && !visited[]) {
        if(min>depth+search())
    } }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N >> H;
    vector<int> box(M * N * H, -1);
    for (int i = 0; i < M * N * H; i++) {
        cin >> box[i];
    }
    int max = -1;
    for (int i = 0; i < M * N * H; i++) {
        if(box[i]==0){
            vector<bool> visited(M * N * H, false);
            int tmp = search(i, 0, visited);
            if (max < se) }
    }
    return 0;
}