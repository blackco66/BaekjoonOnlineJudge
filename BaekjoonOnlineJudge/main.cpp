///#2953

#include <iostream>

using namespace std;

int main() {
	int a[4];
	int index=0, total = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
		int temp_total = a[0] + a[1] + a[2] + a[3];
		if (total < temp_total) {
			total = temp_total;
			index = i + 1;
		}
	}
	printf("%d %d", index, total);
	return 0;
}