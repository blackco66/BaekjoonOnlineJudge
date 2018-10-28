///#1152
#include<iostream>
int main() {
	char c;
	int count = 0;
	scanf("%c", &c);
	while (true) {
		if (c == ' ')scanf("%c", &c);
		else break;
	}
	bool ok = false;
	while (c != '\n') {
		char buff;
		scanf("%c", &buff);
		ok = true;
		if (c == ' '&& buff == ' ')break;
		if (c == ' ' && 
			((buff >= 'A'&&buff <= 'Z') 
				|| (buff >= 'a'&&buff <= 'z')))count++;
		c = buff;
	}
	if (ok == false)printf("0");
	else printf("%d", count + 1);
	return 0;
}