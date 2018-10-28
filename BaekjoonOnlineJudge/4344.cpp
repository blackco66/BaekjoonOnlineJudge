///4344
#include<iostream>
int score[1000];
int main() {
	int t;
	scanf("%d", &t);
	for (int tc=0; tc < t; tc++) {
		int n; scanf("%d", &n);
		int avg = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &score[i]);
			avg += score[i];
		}
		avg /= n;
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (score[i] > avg)count++;
		}
		printf("%.3f", (float)count / n*100);
		std::cout << "%";
		std::cout<<std::endl;
	}
	return 0;
}