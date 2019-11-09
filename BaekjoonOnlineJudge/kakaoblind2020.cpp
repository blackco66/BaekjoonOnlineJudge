#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution1(string s) {
    int answer = s.size();
    int strlen = s.size();
    for (int i = 1; i <= strlen / 2; i++) {
        int len = 0;
        int repeat = 1;
        string prestr = s.substr(0, i);
        len += i;
        for (int j = 1; j < strlen / i; j++) {
            string poststr = s.substr(j * i, i);
            if (prestr == poststr)
                repeat++;
            else {
                if (repeat > 999)
                    len += 4;
                else if (repeat > 99)
                    len += 3;
                else if (repeat > 9)
                    len += 2;
                else if (repeat > 1)
                    len += 1;

                prestr = poststr;
                repeat = 1;
                len += i;
            }
        }
        if (repeat > 999)
            len += 4;
        else if (repeat > 99)
            len += 3;
        else if (repeat > 9)
            len += 2;
        else if (repeat > 1)
            len += 1;
        len += strlen % i;
        if (len < answer) answer = len;
    }
    return answer;
}
bool check2(string p) {
    int cnt = 0;
    int plen = p.size();
    bool flag = true;
    for (int i = 0; i < plen; i++) {
        if (p[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt < 0) {
            flag = false;
            break;
        }
    }
    return flag;
}
string balance2(string p) {
    int cnt = 0;
    int plen = p.size();
    string out = "";
    for (int i = 0; i < plen; i++) {
        if (p[i] == '(')
            cnt++;
        else {
            cnt--;
        }
        if (cnt == 0) {
            out = p.substr(0, i + 1);
            return out;
        }
    }
    return p;
}
string solution2(string p) {
    if (p == "") return "";
    string u = balance2(p);
    if (u.size() == p.size() && check2(u)) return p;
    string v = p.substr(u.size(), p.size() - u.size());
    v = solution2(v);
    if (check2(u)) return u + v;
    string answer = "(" + v + ")";
    string modified_u = u.substr(1, u.size() - 2);
    for (int i = 0; i < modified_u.size(); i++) {
        if (modified_u[i] == '(')
            modified_u[i] = ')';
        else
            modified_u[i] = '(';
    }
    answer += modified_u;

    return answer;
}
bool check3(vector<vector<int>> key, vector<vector<int>> lock, int r, int c) {
    int N = lock.size();
    int M = key.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool flag = i - r >= 0 && j - c >= 0 && i - r < M && j - c < M ? key[i - r][j - c] : false;
            if (!(lock[i][j] ^ flag)) return false;
        }
    }
    return true;
}
bool solution3(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int M = key.size();
    int N = lock.size();
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(key, lock, i, j)) return true;
        }
    }
    vector<vector<int>> m1key(M, vector<int>(M));
    vector<vector<int>> m2key(M, vector<int>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m1key[j][M - 1 - i] = key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m1key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m2key[j][M - 1 - i] = m1key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m2key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m1key[j][M - 1 - i] = m2key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m1key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m1key[i][M - 1 - j] = key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m1key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m2key[j][M - 1 - i] = m1key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m2key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m1key[j][M - 1 - i] = m2key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m1key, lock, i, j)) return true;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m2key[j][M - 1 - i] = m1key[i][j];
        }
    }
    for (int i = -M + 1; i < N - 1; i++) {
        for (int j = -M + 1; j < N - 1; j++) {
            if (check3(m2key, lock, i, j)) return true;
        }
    }
    return false;
}
int count4(vector<string> words, string query) {
    int cnt = 0;
    int qsize = query.size();
    int wsize = words.size();
    for (int i = 0; i < wsize; i++) {
        if (words[i].size() != qsize) continue;
        int flag = 1;
        for (int j = 0; j < qsize; j++) {
            if (query[j] == '?') continue;
            if (words[i][j] != query[j]) {
                flag = 0;
                break;
            }
        }
        cnt += flag;
    }
    return cnt;
}
vector<int> solution4(vector<string> words, vector<string> queries) {
    int quesize = queries.size();
    vector<int> answer(quesize);
    for (int i = 0; i < quesize; i++) {
        answer[i] = count4(words, queries[i]);
    }
    return answer;
}
vector<vector<int>> solution5(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<int>> state(n + 1, vector<int>(n + 1, 0));  //1:기둥, 2: 보, 3: 동시
    int num = build_frame.size();
    for (int i = 0; i < num; i++) {
        vector<int> tmp = build_frame[i];
        int x = tmp[0];
        int y = tmp[1];
        int a = tmp[2]; //0은 기둥, 1은 보
        int b = tmp[3]; //0은 삭제, 1은 설치
        if (a == 0 && b == 0) {
            bool flag = true;
            if (y < n && state[x][y + 1] % 2 == 1 && !((x > 0 && state[x - 1][y + 1] > 1) || (x < n - 1 && state[x][y + 1] > 1))) {
                flag = false;
            } else if (x > 0 && state[x - 1][y + 1] > 1 && !(state[x - 1][y] % 2 == 1 || (x > 1 && y < n && state[x - 2][y + 1] > 1 && state[x][y + 1] > 1))) {
                flag = false;
            } else if (x < n && y < n && state[x][y + 1] > 1 && !(state[x + 1][y] % 2 == 1 || (x > 0 && state[x - 1][y + 1] > 1 && state[x + 1][y + 1] > 1))) {
                flag = false;
            }
            if (flag) {
                state[x][y] -= 1;
            }
        } else if (a == 0 && b == 1) {
            bool flag = false;
            if (y == 0) {
                flag = true;
            } else if (state[x][y - 1] % 2 == 1) {
                flag = true;
            } else if (x > 0 && state[x - 1][y] > 1) {
                flag = true;
            } else if (state[x][y] > 1) {
                flag = true;
            }
            if (flag) {
                state[x][y] += 1;
            }
        } else if (a == 1 && b == 0) {
            bool flag = true;
            if (y < n && state[x][y] % 2 == 1 && !((x > 0 && state[x - 1][y] > 1) || (y > 0 && state[x][y - 1] % 2 == 1))) {
                flag = false;
            } else if (y < n && x < n && state[x + 1][y] % 2 == 1 && !((state[x + 1][y] > 1) || (x < n && y > 0 && state[x + 1][y - 1] % 2 == 1))) {
                flag = false;
            } else if (x > 0 && state[x - 1][y] > 1 && !((y > 0 && state[x][y - 1] % 2 == 1) || (y > 0 && state[x - 1][y - 1] % 2 == 1))) {
                flag = false;
            } else if (x < n - 1 && state[x + 1][y] > 1 && !((y > 0 && state[x + 1][y - 1] % 2 == 1) || (x < n - 1 && y > 0 && state[x + 2][y - 1] % 2 == 1))) {
                flag = false;
            }
            if (flag) {
                state[x][y] -= 2;
            }
        } else if (a == 1 && b == 1) {
            bool flag = false;
            if (state[x][y - 1] % 2 == 1 || state[x + 1][y - 1] % 2 == 1) {
                flag = true;
            } else if (x > 0 && x < n - 1 && state[x - 1][y] > 1 && state[x + 1][y] > 1) {
                flag = true;
            }
            if (flag) {
                state[x][y] += 2;
            }
        }
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (state[i][j] == 0)
                continue;
            else if (state[i][j] == 1) {
                vector<int> tmp{i, j, 0};
                answer.push_back(tmp);
            } else if (state[i][j] == 2) {
                vector<int> tmp{i, j, 1};
                answer.push_back(tmp);
            } else if (state[i][j] == 3) {
                vector<int> tmp1{i, j, 0};
                answer.push_back(tmp1);
                vector<int> tmp2{i, j, 1};
                answer.push_back(tmp2);
            }
        }
    }
    return answer;
}
struct current6{
    bool HV;  //false:horizontal, true:vertical
    int X; 
    int Y;
    int moves;
    current6(bool a, int b, int c, int d) : HV(a), X(b), Y(c), moves(d) {}
};
bool finish6(current6 curr, int n){
    if(!curr.HV && curr.X == n - 2 && curr.Y == n - 1) return true;
    if(curr.HV && curr.X == n - 1 && curr.Y == n - 2) return true;
    return false;
}
int solution6(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    vector<vector<bool>> horizontal(n-1, vector<bool>(n, false));
    vector<vector<bool>> vertical(n, vector<bool>(n-1, false));
    current6 start(false, 0, 0, 0);
    queue<current6> q;
    q.push(start);
	horizontal[start.X][start.Y] = true;
    while(!q.empty()){
        current6 curr = q.front();
        q.pop();
        if(finish6(curr, n)){
            answer = curr.moves;
            break;
        }
        if(!curr.HV){
            if(curr.X < n - 2 && !horizontal[curr.X + 1][curr.Y] && board[curr.Y][curr.X + 2] == 0){
                current6 next(false, curr.X + 1, curr.Y, curr.moves + 1);
                q.push(next);
				horizontal[next.X][next.Y] = true;
            }
            if(curr.X > 0 && !horizontal[curr.X - 1][curr.Y] && board[curr.Y][curr.X - 1] == 0){
                current6 next(false, curr.X - 1, curr.Y, curr.moves + 1);
                q.push(next);
				horizontal[next.X][next.Y] = true;
            }
            if(curr.Y < n - 1 && board[curr.Y + 1][curr.X] == 0 && board[curr.Y + 1][curr.X + 1] == 0){
                if(!horizontal[curr.X][curr.Y + 1]){
                    current6 next(false, curr.X, curr.Y + 1, curr.moves + 1);
                    q.push(next);
					horizontal[next.X][next.Y] = true;
                }
                if(!vertical[curr.X][curr.Y]){
                    current6 next(true, curr.X, curr.Y, curr.moves + 1);
                    q.push(next);
					vertical[next.X][next.Y] = true;
                }
                if(!vertical[curr.X + 1][curr.Y]){
                    current6 next(true, curr.X + 1, curr.Y, curr.moves + 1);
                    q.push(next);
					vertical[next.X][next.Y] = true;
                }
            }
            if(curr.Y > 0 && board[curr.Y - 1][curr.X] == 0 && board[curr.Y - 1][curr.X + 1] == 0){
                if(!horizontal[curr.X][curr.Y - 1]){
                    current6 next(false, curr.X, curr.Y - 1, curr.moves + 1);
                    q.push(next);
					horizontal[next.X][next.Y] = true;
                }
                if(!vertical[curr.X][curr.Y - 1]){
                    current6 next(true, curr.X, curr.Y - 1, curr.moves + 1);
                    q.push(next);
					vertical[next.X][next.Y] = true;
                }
                if(!vertical[curr.X + 1][curr.Y - 1]){
                    current6 next(true, curr.X + 1, curr.Y - 1, curr.moves + 1);
                    q.push(next);
					vertical[next.X][next.Y] = true;
                }
            }
        }
        if(curr.HV){
            if(curr.Y < n - 2 && !vertical[curr.X][curr.Y + 1] && board[curr.Y + 2][curr.X] == 0){
                current6 next(true, curr.X, curr.Y + 1, curr.moves + 1);
                q.push(next);
				vertical[next.X][next.Y] = true;
            }
            if(curr.Y > 0 && !vertical[curr.X][curr.Y - 1] && board[curr.Y - 1][curr.X] == 0){
                current6 next(true, curr.X, curr.Y - 1, curr.moves + 1);
                q.push(next);
				vertical[next.X][next.Y] = true;
            }
            if(curr.X < n - 1 && board[curr.Y][curr.X + 1] == 0 && board[curr.Y + 1][curr.X + 1] == 0){
                if(!vertical[curr.X + 1][curr.Y]){
                    current6 next(true, curr.X + 1, curr.Y, curr.moves + 1);
                    q.push(next);
					vertical[next.X][next.Y] = true;
                }
                if(!horizontal[curr.X][curr.Y]){
                    current6 next(false, curr.X, curr.Y, curr.moves + 1);
                    q.push(next);
					horizontal[next.X][next.Y] = true;
                }
                if(!horizontal[curr.X][curr.Y + 1]){
                    current6 next(false, curr.X, curr.Y + 1, curr.moves + 1);
                    q.push(next);
					horizontal[next.X][next.Y] = true;
                }
            }
            if(curr.X > 0 && board[curr.Y][curr.X - 1] == 0 && board[curr.Y + 1][curr.X - 1] == 0){
                if(!vertical[curr.X - 1][curr.Y]){
                    current6 next(true, curr.X - 1, curr.Y, curr.moves + 1);
                    q.push(next);
					vertical[next.X][next.Y] = true;
                }
                if(!horizontal[curr.X - 1][curr.Y]){
                    current6 next(false, curr.X - 1, curr.Y, curr.moves + 1);
                    q.push(next);
					horizontal[next.X][next.Y] = true;
                }
                if(!horizontal[curr.X - 1][curr.Y + 1]){
                    current6 next(false, curr.X - 1, curr.Y + 1, curr.moves + 1);
                    q.push(next);
					horizontal[next.X][next.Y] = true;
                }
            }
        }
    }
    return answer;
}
int main() {
    vector<int> tmp1{0,0,0,1,1};
    vector<int> tmp2{0,0,0,1,0};
    vector<int> tmp3{0,1,0,1,1};
    vector<int> tmp4{1,1,0,0,1};
    vector<int> tmp5{0,0,0,0,0};
    vector<vector<int>> input;
    input.push_back(tmp1);
    input.push_back(tmp2);
    input.push_back(tmp3);
    input.push_back(tmp4);
    input.push_back(tmp5);

    cout << solution(input);
}