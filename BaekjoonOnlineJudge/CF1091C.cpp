#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main()
{
	__int64 n;
	cin >> n;
	vector<long long> divisors;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if (i != n / i) divisors.push_back(n / i);
		}
	}

	sort(divisors.begin(), divisors.end(), desc);

	for (int i = 0; i < divisors.size(); i++) {
		__int64 k = divisors[i];
		__int64 out = n * (n / k - 1) / 2 + n / k;
		printf("%I64d ", out);
	}
	
	return 0;
}