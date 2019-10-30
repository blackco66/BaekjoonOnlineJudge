#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
	vector<int> ans;

	int a1 = v[0][0];
	int a2 = v[1][1];
	if (a1 == v[0][1])ans.push_back(v[0][2]);
	else ans.push_back(v[0][1]);
	if (a1 == v[1][1])ans.push_back(v[1][2]);
	else ans.push_back(v[1][1]);

	return ans;
}