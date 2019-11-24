#include <bits/stdc++.h>
using namespace std;

int N, W, H;
vector<int> sim(vector<int> input, int col) {
	int top = col;
	while (top < W * H && input[top] == 0) {
		top += W;
	}
	if (top >= W * H)return input;
	queue<int> q;
	q.push(top);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		int val = input[tmp];
		input[tmp] = 0;
		for (int i = 1; i < val; i++) {
			if (tmp - i >= (tmp / W * W) && input[tmp - i] != 0)q.push(tmp - i);
			if (tmp + i < (tmp / W * W + W) && input[tmp + i] != 0)q.push(tmp + i);
			if (tmp - W * i >= 0 && input[tmp - W * i] != 0)q.push(tmp - W * i);
			if (tmp + W * i < W * H && input[tmp + W * i] != 0)q.push(tmp + W * i);
		}
	}
	vector<int> out(W * H, 0);
	for (int i = 0; i < W; i++) {
		int hh = H - 1;
		for (int j = H - 1; j >= 0; j--) {
			if (input[j * W + i] == 0)continue;
			out[hh * W + i] = input[j * W + i];
			hh--;
		}
	}
	return out;
}
int dfs(vector<int> input, int n) {
	int out = W * H;
	if (n == 0) {
		out = 0;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] != 0)out++;
		}
		return out;
	}
	n--;
	for (int i = 0; i < W; i++) {
		vector<int> next = sim(input, i);
		int tmpout = dfs(next, n);
		if (out > tmpout)out = tmpout;
	}
	return out;

}
int main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
		int ans = 0;
		cin >> N >> W >> H;
		vector<int> bricks(W * H);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> bricks[i * W + j];
			}
		}
		ans = dfs(bricks, N);
		cout << "#" << tt << " " << ans << endl;
	}

	return 0;
}