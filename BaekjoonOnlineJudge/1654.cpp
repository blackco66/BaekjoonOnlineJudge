#include <iostream>
using namespace std;
long long k, n;
long long len[10000];
inline bool check(long long cut) {
    long long cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += len[i] / cut;
    }
    return cnt >= n;
}
inline long long find(long long min, long long max) {
    if (min >= max) return max;

    long long mid = (min + max) / 2;

    if (check(mid)) {
        if (max - mid == 1) {
            if (check(max)) {
                return max;
            } else {
                return mid;
            }
        } else
            return find(mid, max);
    } else
        return find(min, mid - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k >> n;
    long long maxlen = -1;
    for (int i = 0; i < k; i++) {
        cin >> len[i];
        if (len[i] > maxlen) maxlen = len[i];
    }
    long long min = maxlen / n > 1 ? maxlen / n : 1;
    long long max = maxlen;
    cout << find(min, max);
    return 0;
}