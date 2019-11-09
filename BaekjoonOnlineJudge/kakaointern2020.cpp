#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define INT_MAX 2147483647
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

using namespace std;

int solution1(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    int num = moves.size();
    int rc = board.size();
    vector<int> tops(rc);
    for (int i = 0; i < rc; i++) {
        for (int j = 0; j < rc; j++) {
            if (board[j][i] != 0) {
                tops[i] = j;
                break;
            }
            if (j == rc - 1) {
                tops[i] = rc;
            }
        }
    }
    for (int i = 0; i < num; i++) {
        if (tops[moves[i] - 1] == rc) continue;
        int cur = moves[i] - 1;
        int poped = board[tops[cur]][cur];
        board[tops[cur]][cur] = 0;
        tops[cur]++;
        if (!basket.empty() && basket.top() == poped) {
            basket.pop();
            answer += 2;
        } else
            basket.push(poped);
    }
    return answer;
}

vector<int> solution2(string s) {
    vector<int> answer;
    vector<vector<int>> keep;
    int strbegin, strend;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{') {
            strbegin = i + 1;
            continue;
        } else if (s[i] == '}') {
            strend = i;
            if (s[i - 1] == '}') break;
            string substr = s.substr(strbegin, strend - strbegin);
            stringstream ss(substr);
            vector<int> tmp;
            while (ss.good()) {
                string tmpstr;
                getline(ss, tmpstr, ',');
                tmp.push_back(stoi(tmpstr));
            }
            sort(tmp.begin(), tmp.end());
            if (keep.size() < tmp.size()) keep.resize(tmp.size());
            keep[tmp.size() - 1] = tmp;
        }
    }
    answer.resize(keep.size());
    for (int i = 0; i < keep.size(); i++) {
        if (i == 0) answer[i] = keep[i][i];
        for (int j = 0; j <= i; j++) {
            if (j < i && keep[i - 1][j] == keep[i][j]) continue;
            answer[i] = keep[i][j];
            break;
        }
    }
    return answer;
}

void dfs3(int ban_num, int cur_num, int cur, const vector<vector<bool>> mapping, vector<int> &match) {
    for (int i = 0; i < mapping[cur_num].size(); i++) {
        if (!mapping[cur_num][i]) continue;
        if ((cur / (1 << i)) % 2 == 1) continue;
        cur += 1 << i;
        if (cur_num == ban_num - 1) {
            bool flag = true;
            for (int j = 0; j < match.size(); j++) {
                if (match[j] == cur) {
                    flag = false;
                    break;
                }
            }
            if (flag) match.push_back(cur);
        } else {
            dfs3(ban_num, cur_num + 1, cur, mapping, match);
        }
        cur -= 1 << i;
    }
}
int solution3(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<bool>> mapping(banned_id.size(), vector<bool>(user_id.size(), false));
    for (int i = 0; i < banned_id.size(); i++) {
        string ban_id = banned_id[i];
        vector<string> tmp = user_id;
        for (int j = 0; j < ban_id.size(); j++) {
            if (ban_id[j] == '*') {
                for (int k = 0; k < tmp.size(); k++) {
                    tmp[k][j] = '*';
                }
            }
        }
        for (int k = 0; k < tmp.size(); k++) {
            if (tmp[k] == ban_id) {
                mapping[i][k] = true;
            }
        }
    }
    int cur = 0;
    vector<int> match;
    dfs3(banned_id.size(), 0, cur, mapping, match);
    answer = match.size();
    return answer;
}

vector<long long> solution4(long long k, vector<long long> room_number) {
    vector<long long> answer;
    vector<long long> occupied;
    answer.push_back(room_number[0]);
    occupied.push_back(room_number[0]);
    for (int i = 1; i < room_number.size(); i++) {
        int in = room_number[i];
        int num = occupied.size();
        for (int j = 0; j < num; j++) {
            if (occupied[j] <= in) {
                if (occupied[j] == in) in++;
                if (j == occupied.size() - 1) {
                    answer.push_back(in);
                    occupied.push_back(in);
                    break;
                }
                continue;
            }
            occupied.insert(occupied.begin() + j, in);
            answer.push_back(in);
            break;
        }
    }
    return answer;
}

int sol5(vector<int> stones, int k, int n, int maximum) {
    int cont = 0;
    int minmin = 2147483647;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] > n) {
            if (minmin > stones[i]) minmin = stones[i];
            cont = 0;
            continue;
        }
        cont++;
        if (cont >= k) return n;
    }
    return sol5(stones, k, minmin, maximum);
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int minimum = 2147483647;
    int maximum = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (minimum > stones[i]) minimum = stones[i];
        if (maximum < stones[i]) maximum = stones[i];
    }
    answer = sol5(stones, k, minimum, maximum);
    return answer;
}

int main() {
    vector<int> tmp1{0, 0, 0, 0, 0};
    vector<int> tmp2{0, 0, 1, 0, 3};
    vector<int> tmp3{0, 2, 5, 0, 1};
    vector<int> tmp4{4, 2, 4, 4, 2};
    vector<int> tmp5{3, 5, 1, 3, 1};
    vector<vector<int>> input;
    vector<int> input2{1, 5, 3, 5, 1, 2, 1, 4};
    input.push_back(tmp1);
    input.push_back(tmp2);
    input.push_back(tmp3);
    input.push_back(tmp4);
    input.push_back(tmp5);
    string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
    vector<string> in{"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> in2{"*rodo", "*rodo", "******"};
    vector<int> in3{2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    solution(in3, 3);
}