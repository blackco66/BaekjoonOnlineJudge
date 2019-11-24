#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
struct info {
	int item;
	double rate;
	info(int ii, double rr) : item(ii), rate(rr) {}
};
double cal_simil(vector<info> u1info, vector<info> u2info,
	double u1avg, double u2avg) {
	vector<double> diff1, diff2;
	for (int i = 0; i < u1info.size(); i++) {
		for (int j = 0; j < u2info.size(); j++) {
			if (u1info[i].item != u2info[j].item)continue;
			diff1.push_back(u1info[i].rate - u1avg);
			diff2.push_back(u2info[j].rate - u2avg);
		}
	}
	double numer = 0;
	double denom1 = 0;
	double denom2 = 0;
	for (int i = 0; i < diff1.size(); i++) {
		numer += diff1[i] * diff2[i];
		denom1 += diff1[i] * diff1[i];
		denom2 += diff2[i] * diff2[i];
	}
	denom1 = sqrt(denom1);
	denom2 = sqrt(denom2);
	if (denom1 * denom2 == 0)return 0;
	return numer / (denom1 * denom2);
}
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num_sim_user_topk = 0;
	int num_item_rec_topk = 0;
	int num_users = 0;
	int num_items = 0;
	int num_rows = 0;
	cin >> num_sim_user_topk >> num_item_rec_topk;
	cin >> num_users >> num_items >> num_rows;
	vector<vector<info>> input(301);
	bool users[301];
	bool items[71];
	bool user_item[301][71];
	double rates[301][71];
	vector<int> user_ids;
	vector<int> item_ids;
	for (int i = 0; i < 301; i++) {
		users[i] = false;
		for (int j = 0; j < 71; j++) {
			user_item[i][j] = false;
		}
	}
	for (int i = 0; i < 71; i++) {
		items[i] = false;
	}
	for (int i = 0; i < num_rows; i++) {
		int tmp_user;
		int tmp_item;
		double tmp_rate;
		cin >> tmp_user >> tmp_item >> tmp_rate;
		tmp_rate *= 10;
		info tmp(tmp_item, tmp_rate);
		input[tmp_user].push_back(tmp);
		users[tmp_user] = true;
		items[tmp_item] = true;
		user_item[tmp_user][tmp_item] = true;
		rates[tmp_user][tmp_item] = tmp_rate;
	}
	for (int i = 1; i < 301; i++) {
		if (users[i]) user_ids.push_back(i);
	}
	for (int i = 1; i < 71; i++) {
		if (items[i]) item_ids.push_back(i);
	}
	num_items = item_ids.size();
	num_users = user_ids.size();
	int num_reco_users = 0;
	cin >> num_reco_users;
	vector<int> out_users(num_reco_users);
	for (int i = 0; i < num_reco_users; i++) {
		cin >> out_users[i];
	}
	/* input until here */
	vector<double> user_rate_avg(num_users, 0);
	for (int i = 0; i < num_users; i++) {
		vector<info> tmp_user_infos = input[user_ids[i]];
		for (int j = 0; j < tmp_user_infos.size(); j++) {
			user_rate_avg[i] += tmp_user_infos[j].rate;
		}
		user_rate_avg[i] /= tmp_user_infos.size();
	}
	vector<vector<double>> simil(num_users, vector<double>(num_users, 0));
	for (int i = 0; i < num_users - 1; i++) {
		for (int j = i + 1; j < num_users; j++) {
			if (i == j) {
				simil[i][j] = 1;
				break;
			}
			simil[i][j] = simil[j][i] = cal_simil(input[user_ids[i]], input[user_ids[j]], user_rate_avg[i], user_rate_avg[j]);
		}
	}
	vector<vector<int>> uprime(num_users, vector<int>(num_sim_user_topk));
	for (int i = 0; i < num_users; i++) {
		vector<double> tmp_simil(simil[i].size());
		for (int j = 0; j < simil[i].size(); j++) {
			tmp_simil[j] = simil[i][j];
		}
		sort(tmp_simil.begin(), tmp_simil.end());
		for (int j = tmp_simil.size() - 1; j >= tmp_simil.size() - num_sim_user_topk; j--) {
			for (int k = 0; k < simil[i].size(); k++) {
				if (tmp_simil[j] == simil[i][k] && i != k) {
					uprime[i][tmp_simil.size() - j - 1] = k;
					break;
				}
			}
		}
	}

	/*TODO: ks를 item별로 다시 계산해야함*/
	/*vector<double> ks(num_users, 0);
	for (int i = 0; i < num_users; i++) {
		double tmp_sum = 0;
		for (int j = 0; j < num_sim_user_topk; j++) {
			tmp_sum += simil[i][uprime[i][j]] > 0 ? simil[i][uprime[i][j]] : -simil[i][uprime[i][j]];
		}
		ks[i] = 1 / tmp_sum;
	}*/
	/* simil[][], ks[], user_rate_avg[], uprime[][] */
	for (int i = 0; i < num_reco_users; i++) {
		int out_user_id = out_users[i];
		int ididx = -1;
		for (int j = 0; j < user_ids.size(); j++) {
			if (user_ids[j] == out_user_id) {
				ididx = j;
				break;
			}
		}
		vector<double> tmp_simil = simil[ididx];
		double tmp_avg = user_rate_avg[ididx];
		vector<int> tmp_uprime = uprime[ididx];

		vector<double> reco_score(num_items, -99999);
		vector<int> reco_ids;
		for (int j = 0; j < num_items; j++) {
			if (j == 5) {
				int a=0;
				a++;
			}
			if (user_item[user_ids[ididx]][item_ids[j]] == true)continue;
			
			/* k값 계산*/
			double kkk = 0;
			double right = 0;
			for (int k = 0; k < tmp_uprime.size(); k++) {
				if (!user_item[user_ids[tmp_uprime[k]]][item_ids[j]])continue;
				kkk += simil[ididx][tmp_uprime[k]] > 0 ? simil[ididx][tmp_uprime[k]] : -simil[ididx][tmp_uprime[k]];

				right += simil[ididx][tmp_uprime[k]] * (rates[user_ids[tmp_uprime[k]]][item_ids[j]] - user_rate_avg[tmp_uprime[k]]);
			}
			reco_score[j] = tmp_avg;
			if (kkk != 0) {
				double rights = right / kkk;
				reco_score[j] += rights;
			}
		}

		for (int j = 0; j < num_item_rec_topk; j++) {
			int max_idx = -1;
			double mmax = -999999;
			for (int k = 0; k < reco_score.size(); k++) {
				if (mmax < reco_score[k]) {
					mmax = reco_score[k];
					max_idx = k;
				}
			}
			reco_score[max_idx] = -99999;
			cout << item_ids[max_idx] << " ";
		}
		cout << endl;
	}
	return 0;
}