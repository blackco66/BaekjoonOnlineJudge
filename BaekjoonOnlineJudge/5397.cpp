#include <iostream>
#include <list>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        list<char> pw;
        pw.push_back('0');
        list<char>::iterator it = pw.begin();
        char in;
        scanf("%c", &in);
        while (in == '\n') scanf("%c", &in);

        while (in != '\n') {
            list<char>::iterator last_it = pw.end();
            last_it--;
            if (in != '<' && in != '>' && in != '-') {
                pw.insert(++it, in);
                it--;
            } else if (in == '<' && it != pw.begin())
                it--;
            else if (in == '>' && it != last_it)
                it++;
            else if (in == '-' && it != pw.begin()) {
                it = pw.erase(it);
                it--;
            }
            scanf("%c", &in);
        }
        pw.erase(pw.begin());
        it = pw.begin();
        for (int i = 0; i < pw.size(); i++) {
            cout << *it++;
        }
        cout << endl;
        n--;
    }
    return 0;
}