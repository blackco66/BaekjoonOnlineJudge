///#3052

#include <iostream>
#include<unordered_set>
using namespace std;

int main() {
	int i = 10;
	unordered_set<int> set;
	while (i > 0) {
		int temp;
		scanf("%d", &temp);
		temp %= 42;
		set.insert(temp);
		i--;
	}
	cout << set.size();
	return 0;
}