///#5554

#include<iostream>
#include<string>
using namespace std;

int main() {
	int temp, total = 0;
	int n = 4;
	while (n > 0) {
		cin >> temp;
		total += temp;
		n--;
	}
	cout << total / 60 << endl;
	cout << total % 60;
	return 0;
}