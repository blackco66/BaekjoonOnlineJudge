///#3053

#include <iostream>
using namespace std;

int main() {
	double n;
	cin >> n;
	const double PI = 3.14159265358979323846;
	printf("%.6f\n%.6f", PI*n*n, 2 * n*n);
	return 0;
}