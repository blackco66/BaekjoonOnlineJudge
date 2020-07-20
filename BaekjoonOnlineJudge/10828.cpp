//10828
#include <iostream>
using namespace std;
char input[6];
int stack[10000];
int sz = 0;
void Push(int X) {
    stack[sz] = X;
    sz++;
}
int Pop() {
    if (sz == 0) return -1;
    sz--;
    return stack[sz];
}
int Empty() {
    if (sz == 0) return 1;
    return 0;
}
int Top() {
    if (sz == 0) return -1;
    return stack[sz - 1];
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char tc;
        scanf("%c", &tc);
        if (tc == '\n') {
            scanf("%c", &tc);
        }
        int len = 0;
        while (tc >= 'a' && tc <= 'z') {
            input[len] = tc;
            len++;
            scanf("%c", &tc);
        }
        if (input[1] == 'u') {
            int x;
            scanf("%d", &x);
            Push(x);
        } else if (input[0] == 'p' && input[1] == 'o') {
            printf("%d\n", Pop());
        } else if (input[1] == 'i') {
            printf("%d\n", sz);
        } else if (input[1] == 'm') {
            printf("%d\n", Empty());
        } else if (input[0] == 't' && input[1] == 'o') {
            printf("%d\n", Top());
        }
    }
    return 0;
}