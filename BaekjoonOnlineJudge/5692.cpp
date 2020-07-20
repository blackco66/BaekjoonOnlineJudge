#include <iostream>
using namespace std;
int fact[100];
int factorial(int ff) {
    if (fact[ff] != 0) {
        return fact[ff];
    }
    fact[ff] = factorial(ff - 1) * ff;
    return fact[ff];
}
int main() {
    fact[1] = 1;
    int a;
    scanf("%d", &a);
    while (1) {
        int res = 0;
        int fac = 1;
        while (a != 0) {
            res += a % 10 * factorial(fac);
            fac++;
            a /= 10;
        }
        printf("%d\n", res);
        scanf("%d", &a);
        if (a == 0) break;
    }
    return 0;
}