#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int M, N, H;
int tot = 0;
int ripe = 0;
int box[1000000];
int conv(int i, int j, int k) {
    return i + M * j + M * N * k;
    /*if (out < 0 || out > M * N * H - 1) {
        cout << "error!!!!";
        return 1;
    } else {
        return out;
    }*/
}
bool oneDay(int box[]) {
    stack<int> expect;
	for (int i = 0; i < M * N * H; i++) {
		if (box[i] == 0) {
			int x = i % M;
			int y = (i / M) % N;
			int z = i / (M * N);
			//if (conv(x, y, z) != i)cout << "error!!!!!!!";
			bool flag = (x > 0 && box[conv(x - 1, y, z)] == 1) ||
				(y > 0 && box[conv(x, y - 1, z)] == 1) ||
				(z > 0 && box[conv(x, y, z - 1)] == 1) ||
				(x < M - 1 && box[conv(x + 1, y, z)] == 1) ||
				(y < N - 1 && box[conv(x, y + 1, z)] == 1) ||
				(z < H - 1 && box[conv(x, y, z + 1)] == 1);
			if (flag) {
				expect.push(i);
			}
		}        
    }
    bool out = (!expect.empty());
    while (!expect.empty()) {
        int tmp = expect.top();
        expect.pop();
        box[tmp] = 1;
        ripe++;
    }
    return out;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	memset(box, -1, sizeof(box));
    cin >> M >> N >> H;
    for (int i = 0; i < M * N * H; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            tot++;
			box[i] = 0;
        } else if (tmp == 1) {
            tot++;
            ripe++;
            box[i] = 1;
		}
    }
    int cnt = 0;
    while (1) {
        if (oneDay(box)) {
            cnt++;
        } else {
            break;
        }
    }
    if (tot == ripe) {
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}