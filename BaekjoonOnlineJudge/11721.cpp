///#11721
#include<iostream>
#include<string>
using namespace std;
int main() {
	int ten = 0;
	string st;
	getline(cin, st);
	int count = 0;
	for(int i=0;i<st.size();i++) {
		printf("%c", st[count]);
		if (count % 10 == 9)printf("\n");
		count++;
	}
	
	return 0;
}