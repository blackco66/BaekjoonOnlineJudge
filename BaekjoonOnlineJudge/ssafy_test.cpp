#include<bits/stdc++.h>
using namespace std;

int pb(int n, int a, int b) {
	if (n == 2)return b;
	else return pb(n - 1, b, a + b);
}
int step(string c, int k, int in) {
	if (c == "o")return in;
	int out = 0;
	for (int i = 1; i <= k; i++) {
		if (c.substr(i)=="")break;
		if (c[i] == 'o')out += step(c.substr(i),k,in);
	}
	return in * out;
}
int main() {
	int k = 4;
	string c = "oooooooooxooooooooooo";
	cout << step(c, k, 1);
	return 0;
}