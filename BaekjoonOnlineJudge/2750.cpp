#include <iostream>
using namespace std;
int N[1000];
int num;
void swap(int idx1, int idx2) {
    int temp = N[idx1];
    N[idx1] = N[idx2];
    N[idx2] = temp;
}
int partition(int begin, int end) {
    int pivot = N[begin];
    int left = begin;
    int right = end + 1;
    while (left < right) {
        do {
            left++;
        } while (left <= end && N[left] < pivot);
        do {
            right--;
        } while (right >= begin && N[right] > pivot);
        if (left < right) {
            swap(left, right);
        }
    }
    swap(begin, right);
    return right;
}
void qs(int begin, int end) {
    if (begin < end) {
        int p = partition(begin, end);
        qs(begin, p - 1);
        qs(p + 1, end);
    }
}
int main() {
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> N[i];
    }
    qs(0, num - 1);
    for (int i = 0; i < num; i++) {
        cout << N[i] << endl;
    }
    return 0;
}