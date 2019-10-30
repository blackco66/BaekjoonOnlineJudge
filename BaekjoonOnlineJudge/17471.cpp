#include <iostream>
#include <vector>
using namespace std;
int ans;
int N;
int p[10];
vector<int> edge[10];
vector<int> visited;
void dfs(int v, vector<int> a) {
	for (int i = 0; i < edge[v].size(); i++) {
		if(visited.find(edge[v][i]))
	}
}
void check(int bit) {
	vector<int> a, b;
	int avalue = 0, bvalue = 0;
	for (int i = 0; i < N; i++) {
		int pos = 1 << i;
		if (bit & pos) {
			a.push_back(i);
			avalue += p[i];
		}
		else {
			b.push_back(i);
			bvalue += p[i];
		}
	}
	visited.push_back(a[0]);
	dfs(a[0], a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ans = 10000;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
	for (int i = 0; i < N; i++) {
		int tmpnum;
		cin >> tmpnum;
		for (int j = 0; j < tmpnum; j++) {
			int neighbor;
			cin >> neighbor;
			edge[i].push_back(neighbor - 1);
		}
	}
	for (int bit = 1; bit < (1 << N) - 1; bit++) {
		check(bit);
	}
    return 0;
}