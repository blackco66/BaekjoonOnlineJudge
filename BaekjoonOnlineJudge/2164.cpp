// 2164
#include <iostream>
using namespace std;

int n;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int dd) : data(dd), next(NULL), prev(NULL) {}
};
int main() {
    cin >> n;
    Node* it = new Node(n);
    it->next = it;
    it->prev = it;
    for (int i = n - 1; i > 0; i--) {
        Node* nNode = new Node(i);
        if (i == n - 1) {
            it->next = nNode;
            it->prev = nNode;
            nNode->next = it;
            nNode->prev = it;
            it = nNode;
        } else {
            nNode->next = it->next;
            nNode->prev = it;
            it->next->prev = nNode;
            it->next = nNode;
            it = nNode;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        Node* tmp = it;
        it->prev->next = it->next;
        it->next->prev = it->prev;
        it = it->prev->prev;
        delete tmp;
    }
    cout << it->data;
    delete it;
    return 0;
}