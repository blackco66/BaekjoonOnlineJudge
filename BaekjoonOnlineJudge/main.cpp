///#1065

#include <iostream>

using namespace std;
bool check_arithmetic(int num){
	int a100 = num / 100;
	int a10 = (num - 100 * a100) / 10;
	int a1 = num % 10;
	if (a100 - a10 == a10 - a1)return true;
	else return false;
}
int main() {
	int n;
	int ans = 0;
	scanf("%d", &n);
	if (n < 100) {
		printf("%d", n);
		return 0;
	}
	else {
		if (n == 1000)n = 999;
		while (n > 99) {
			if (check_arithmetic(n))ans++;
			n--;
		}
		printf("%d", ans+99);
	}

	return 0;
}