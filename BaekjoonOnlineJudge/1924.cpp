///#1924
#include<iostream>
using namespace std;

int main() {
	int m, d;
	cin >> m >> d;
	for (int i = 1; i < m; i++) {
		if (i==1||i==3||i==5||i==7||i==8||i==10)d += 31;
		else if (i==4||i==6||i==9||i==11)d += 30;
		else d += 28;
	}
	d %= 7;
	switch (d)
	{
	case 1:
		printf("MON");
		break;
	case 2:
		printf("TUE");
		break;
	case 3:
		printf("WED");
		break;
	case 4:
		printf("THU");
		break;
	case 5:
		printf("FRI");
		break;
	case 6:
		printf("SAT");
		break;
	case 0:
		printf("SUN");
		break;
	default:
		break;
	}
	return 0;
}