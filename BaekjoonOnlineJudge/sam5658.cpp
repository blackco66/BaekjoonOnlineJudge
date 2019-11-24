#include<bits/stdc++.h>
using namespace std;
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else {
		return c - 'A' + 10;
	}
}
int vtoi(vector<char> input, int begin, int end) {
	int out = 0;
	for (int i = end; i >= begin; i--) {
		out += ctoi(input[i]) * (1 << (4 * (end - i)));
	}
	return out;
}
int main() {
	int tc;
	cin >> tc;
	for (int ttt = 0; ttt < tc; ttt++) {
		int N, K;
		cin >> N >> K;
		int side = N / 4;
		vector<char> input(N + side - 1);
		for (int i = 0; i < N; i++) {
			char tmp;
			cin >> tmp;
			input[side - 1 + i] = tmp;
			if (i > 3 * side) {
				input[i - 3 * side - 1] = tmp;
			}
		}
		vector<int> array(4 * side);
		for (int i = 0; i < side; i++) {
			array[i * 4] = vtoi(input, i, i + side - 1);
			array[i * 4 + 1] = vtoi(input, i + side, i + 2 * side - 1);
			array[i * 4 + 2] = vtoi(input, i + 2 * side, i + 3 * side - 1);
			array[i * 4 + 3] = vtoi(input, i + 3 * side, i + 4 * side - 1);
		}
		sort(array.begin(), array.end());
		int prev = -1;
		int ii = 4 * side;
		while (K > 0) {
			ii--;
			if (prev == array[ii])continue;
			prev = array[ii];
			K--;
		}
		cout << "#" << ttt + 1 << " " << array[ii] << endl;
	}
	return 0;
}