#include <iostream>
using namespace std;
int effort(int a, int b) {
    if (a == b) return 0;
    if (b < a) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (a == 0) {
        if (b == 1 || b == 3) return 4;
        if (b == 2 || b == 4 || b == 6) return 3;
        if (b == 5 || b == 7 || b == 9) return 2;
        if (b == 8) return 1;
        return 10000;
    } else if (a == 1) {
        if (b == 9) return 4;
        if (b == 6 || b == 8) return 3;
        if (b == 3 || b == 5 || b == 7) return 2;
        if (b == 2 || b == 4) return 1;
    } else if (a == 2) {
        if (b == 7 || b == 9) return 3;
        if (b == 4 || b == 6 || b == 8) return 2;
        if (b == 3 || b == 5) return 1;
    } else if (a == 3) {
        if (b == 7) return 4;
        if (b == 4 || b == 8) return 3;
        if (b == 5 || b == 9) return 2;
        if (b == 6) return 1;
    } else if (a == 4) {
        if (b == 9) return 3;
        if (b == 6 || b == 8) return 2;
        if (b == 5 || b == 7) return 1;
    } else if (a == 5) {
        if (b == 7 || b == 9) return 2;
        if (b == 6 || b == 8) return 1;
    } else if (a == 6) {
        if (b == 7) return 3;
        if (b == 8) return 2;
        if (b == 9) return 1;
    } else if (a == 7) {
        if (b == 9) return 2;
        if (b == 8) return 1;
    } else if (a == 8){
        if (b == 9) return 1;
    }
    return 10000;
}
int main() {
    int hour, min;
    char dot;
    cin >> hour >> dot >> min;
	int min_effort = 10000;
	int min_digit1;
	int min_digit2;
	int min_digit3;
	int min_digit4;
	for (int h = hour; h < 100; h += 24) {
		for (int m = min; m < 100; m += 60) {
			int digit1 = h / 10;
			int digit2 = h % 10;
			int digit3 = m / 10;
			int digit4 = m % 10;
			int tmp_effort = effort(digit1, digit2) + effort(digit2, digit3) + effort(digit3, digit4);
			if (tmp_effort < min_effort) {
				min_effort = tmp_effort;
				min_digit1 = digit1;
				min_digit2 = digit2;
				min_digit3 = digit3;
				min_digit4 = digit4;
			}
		}
	}
	cout << min_digit1 << min_digit2 << ":" << min_digit3 << min_digit4 << endl;

    return 0;
}