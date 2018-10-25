///#1713

#include <iostream>
#include <algorithm>
using namespace std;
struct picture {
	int index;
	int num_of_recommands = 0;
	int refreshed_moment;
	picture() {
		index = -1;
		num_of_recommands = 0;
		refreshed_moment = -1;
	}
}frames[20];
bool compare(picture lhs, picture rhs) { return lhs.index < rhs.index; }
int n, total;
/**
	purpose: increase num_of_recommands if exists than return true
*/
bool check_existence(int recommand) {
	for (int i = 0; i < n; i++) {
		if (frames[i].index == recommand) {
			frames[i].num_of_recommands++;
			return true;
		}
	}
	return false;
}
void find_lowest_recommand(int recommand, int refresh) {
	int lowest = 0;
	for (int i = 0; i < n; i++) {
		if (frames[lowest].num_of_recommands > frames[i].num_of_recommands)
			lowest = i;
		else if (frames[lowest].num_of_recommands == frames[i].num_of_recommands) {
			if (frames[lowest].refreshed_moment > frames[i].refreshed_moment)
				lowest = i;
		}
	}
	frames[lowest].index = recommand;
	frames[lowest].num_of_recommands = 1;
	frames[lowest].refreshed_moment = refresh;
	return;
}
void simulation(int recommand,int refresh) {
	if (check_existence(recommand))return;
	find_lowest_recommand(recommand, refresh);
	return;
}
int main() {
	cin >> n >> total;
	for (int i = 0; i < total; i++) {
		int recommad;
		cin >> recommad;
		simulation(recommad,i);
	}
	sort(frames, frames + n, compare);
	for (int i = 0; i < n; i++) {
		cout << frames[i].index << " ";
	}
	return 0;
}