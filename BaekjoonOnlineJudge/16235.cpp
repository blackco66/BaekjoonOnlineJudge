#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int A[10][10];
int cur[10][10];
int N, M, K;

vector<int> spring(vector<vector<int>> &trees) {
	vector<int> dietrees(N * N);
	for (int i = 0; i < N * N; i++) {
		sort(trees[i].begin(), trees[i].end());
		int die = -1;
		for (int j = 0; j < trees[i].size(); j++) {
			if (cur[i / N][i % N] - trees[i][j] < 0) {
				die = j;
				break;
			}
			cur[i / N][i % N] -= trees[i][j];
			trees[i][j]++;
		}
		dietrees[i] = die;
	}
	return dietrees;
}
void summer(vector<vector<int>> &trees, vector<int> dietrees){
	for (int i = 0; i < N * N; i++) {
		if (dietrees[i] == -1) continue;
		for (int j = dietrees[i]; j < trees[i].size(); j++) {
			cur[i / N][i % N] += trees[i][j] / 2;
		}
		trees[i].erase(trees[i].begin() + dietrees[i], trees[i].end());
	}
}
void fall(vector<vector<int>>& trees) {
	for (int i = 0; i < N * N; i++) {
		for (int j = 0; j < trees[i].size(); j++) {
			if (trees[i][j] % 5 == 0) {
				if (i % N != 0) {
					trees[i - 1].push_back(1);
					if (i / N != 0) trees[i - 1 - N].push_back(1);
					if (i / N != N - 1) trees[i - 1 + N].push_back(1);
				}
				if (i % N != N - 1) {
					trees[i + 1].push_back(1);
					if (i / N != 0) trees[i + 1 - N].push_back(1);
					if (i / N != N - 1) trees[i + 1 + N].push_back(1);
				}
				if (i / N != 0) trees[i - N].push_back(1);
				if (i / N != N-1) trees[i + N].push_back(1);
			}
		}
	}
}
void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cur[i][j] += A[i][j];
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			cur[i][j] = 5;
		}
	}
	vector<vector<int>> trees(N * N);
	for (int i = 0; i < M; i++) {
		int tmpx, tmpy, tmpz;
		cin >> tmpx >> tmpy >> tmpz;
		trees[(tmpx - 1) * N + (tmpy - 1)].push_back(tmpz);
	}
	for (int i = 0; i < K; i++) {
		vector<int> dietrees = spring(trees);
		summer(trees, dietrees);
		fall(trees);
		winter();
	}
	int num = 0;
	for (int i = 0; i < N * N; i++) {
		num += trees[i].size();
	}
	cout << num;
	return 0;
}