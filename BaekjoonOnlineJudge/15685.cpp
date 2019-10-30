#include <iostream>
#include <utility>
#include <vector>
using namespace std;
struct curve {
    int x, y, d, g;
    curve(int xx, int yy, int dd, int gg) : x(xx), y(yy), d(dd), g(gg) {}
    curve() {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int maxGen = 0;
    cin >> N;
    vector<curve> input(N);
    for (int i = 0; i < N; i++) {
        int tx, ty, td, tg;
        cin >> tx >> ty >> td >> tg;
        curve tmpcurve(tx, ty, td, tg);
        input[i] = tmpcurve;
        if (maxGen < tg) maxGen = tg;
    }
    bool points[101][101];
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            points[i][j] = false;
        }
    }
    vector<vector<pair<int, int>>> dragoncurves(maxGen + 1);
    dragoncurves[0].push_back(make_pair(0, 0));
    dragoncurves[0].push_back(make_pair(1, 0));
    for (int i = 1; i <= maxGen; i++) {
        dragoncurves[i] = dragoncurves[i - 1];
        dragoncurves[i].resize(dragoncurves[i - 1].size() * 2 - 1);
        int centerx = dragoncurves[i - 1].back().first;
        int centery = dragoncurves[i - 1].back().second;
        for (int j = dragoncurves[i - 1].size() - 2; j >= 0; j--) {
            int transx = centerx + centery - dragoncurves[i - 1][j].second;
            int transy = -centerx + centery + dragoncurves[i - 1][j].first;
            dragoncurves[i][dragoncurves[i - 1].size() * 2 - j - 2] = make_pair(transx, transy);
        }
    }
    for (int i = 0; i < N; i++) {
        curve cur = input[i];
        if (cur.d == 0) {
            for (int j = 0; j < dragoncurves[cur.g].size(); j++) {
                int tmpx = cur.x + dragoncurves[cur.g][j].first;
                int tmpy = cur.y + dragoncurves[cur.g][j].second;
                points[tmpy][tmpx] = true;
            }
        } else if (cur.d == 1) {
            for (int j = 0; j < dragoncurves[cur.g].size(); j++) {
                int tmpx = cur.x + dragoncurves[cur.g][j].second;
                int tmpy = cur.y - dragoncurves[cur.g][j].first;
                points[tmpy][tmpx] = true;
            }
        } else if (cur.d == 2) {
            for (int j = 0; j < dragoncurves[cur.g].size(); j++) {
                int tmpx = cur.x - dragoncurves[cur.g][j].first;
                int tmpy = cur.y - dragoncurves[cur.g][j].second;
                points[tmpy][tmpx] = true;
            }
        } else if (cur.d == 3) {
            for (int j = 0; j < dragoncurves[cur.g].size(); j++) {
                int tmpx = cur.x - dragoncurves[cur.g][j].second;
                int tmpy = cur.y + dragoncurves[cur.g][j].first;
                points[tmpy][tmpx] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (points[i][j] && points[i + 1][j] && points[i][j + 1] && points[i + 1][j + 1]) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}