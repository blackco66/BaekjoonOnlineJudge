#include <iostream>
#include <vector>
using namespace std;

int fin;
size_t row, col;

int search_hog(int hog, int step, vector<int> water, vector<bool> water_map,
               vector<bool> rock) {
    if (hog == fin) return step;
    int hog_row = hog / col;
    int hog_col = hog % col;
    if ((!(hog_row > 0) ||
         (hog_row > 0 && rock[hog - col] && water_map[hog - col])) &&
        (!(hog_row < row - 1) ||
         (hog_row < row - 1 && rock[hog + col] && water_map[hog + col])) &&
        (!(hog_col > 0) ||
         (hog_col > 0 && rock[hog - 1] && water_map[hog - 1])) &&
        (!(hog_col < col - 1) ||
         (hog_col < col - 1 && rock[hog + 1] && !water_map[hog + 1]))) {
        return 3000;
    }
    rock[hog] = true;
    vector<int> tmp_water;
    // water flow
    for (vector<int>::iterator iter = water.begin(); iter != water.end();
         iter++) {
        int t_water = *iter;
        int t_row = t_water / col;
        int t_col = t_water % col;
        int north = t_water - col;
        int south = t_water + col;
        int east = t_water + 1;
        int west = t_water - 1;
        if (t_row > 0) {
            if (!rock[north] && !water_map[north] && fin != north) {
                tmp_water.push_back(north);
                water_map[north] = true;
            }
        }
        if (t_row < row - 1) {
            if (!rock[south] && !water_map[south] && fin != south) {
                tmp_water.push_back(south);
                water_map[south] = true;
            }
        }
        if (t_col > 0) {
            if (!rock[west] && !water_map[west] && fin != west) {
                tmp_water.push_back(west);
                water_map[west] = true;
            }
        }
        if (t_col < col - 1) {
            if (!rock[east] && !water_map[east] && fin != east) {
                tmp_water.push_back(east);
                water_map[east] = true;
            }
        }
    }
    for (vector<int>::iterator iter = tmp_water.begin();
         iter != tmp_water.end(); iter++) {
        water.push_back(*iter);
    }
    //
    int res = 3000;

    if (hog_row > 0) {
        if (!rock[hog - col] && !water_map[hog - col]) {
            int tmp = search_hog(hog - col, step + 1, water, water_map, rock);
            if (tmp < res) res = tmp;
        }
    }
    if (hog_row < row - 1) {
        if (!rock[hog + col] && !water_map[hog + col]) {
            int tmp = search_hog(hog + col, step + 1, water, water_map, rock);
            if (tmp < res) res = tmp;
        }
    }
    if (hog_col > 0) {
        if (!rock[hog - 1] && !water_map[hog - 1]) {
            int tmp = search_hog(hog - 1, step + 1, water, water_map, rock);
            if (tmp < res) res = tmp;
        }
    }
    if (hog_col < col - 1) {
        if (!rock[hog + 1] && !water_map[hog + 1]) {
            int tmp = search_hog(hog + 1, step + 1, water, water_map, rock);
            if (tmp < res) res = tmp;
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> row >> col;
    int hog;
    vector<int> water;
    vector<bool> water_map(row * col, false);
    vector<bool> rock(row * col, false);
    for (int i = 0; i < row * col; i++) {
        char tmp;
        scanf("%c", &tmp);
        if (tmp == '*') {
            water.push_back(i);
            water_map[i] = true;
        } else if (tmp == 'X') {
            rock[i] = true;
        } else if (tmp == 'D') {
            fin = i;
        } else if (tmp == 'S') {
            hog = i;
        }
    }
    int result = search_hog(hog, 0, water, water_map, rock);
    if (result == 3000) {
        cout << "KAKTUS" << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}