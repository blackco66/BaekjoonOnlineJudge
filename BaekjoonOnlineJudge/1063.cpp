#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char king_char, rock_char;
	int king_row, rock_row;
	int N;
	cin >> king_char >> king_row;
	cin >> rock_char >> rock_row;
	cin >> N;
	int king_col = king_char - 'A' + 1;
	int rock_col = rock_char - 'A' + 1;
	for (int i = 0; i < N; i++) {
		string move;
		cin >> move;
		if (move == "R") {
			if (king_row == rock_row && king_col + 1 == rock_col) {
				if (king_col < 8 && rock_col < 8) {
					king_col++;
					rock_col++;
				}
			}
			else {
				if (king_col < 8) {
					king_col++;
				}
			}
		}
		else if (move == "L") {
			if (king_row == rock_row && king_col - 1 == rock_col) {
				if (king_col > 1 && rock_col > 1) {
					king_col--;
					rock_col--;
				}
			}
			else {
				if (king_col > 1) {
					king_col--;
				}
			}
			
		}
		else if (move == "B") {
			if (king_col == rock_col && king_row - 1 == rock_row) {
				if (king_row > 1 && rock_row > 1) {
					king_row--;
					rock_row--;
				}
			}
			else {
				if (king_row > 1) {
					king_row--;
				}
			}
			
		}
		else if (move == "T") {
			if (king_col == rock_col && king_row + 1 == rock_row) {
				if (king_row < 8 && rock_row < 8) {
					king_row++;
					rock_row++;
				}
			}
			else {
				if (king_row < 8) {
					king_row++;
				}
			}
			
		}
		else if (move == "RT") {
			if (king_row + 1 == rock_row && king_col + 1 == rock_col) {
				if (king_row < 8 && rock_row < 8 && king_col < 8 && rock_col < 8) {
					king_row++;
					rock_row++;
					king_col++;
					rock_col++;
				}
			}
			else {
				if (king_row < 8 && king_col < 8) {
					king_row++;
					king_col++;
				}
			}
		}
		else if (move == "LT") {
			if (king_row + 1 == rock_row && king_col - 1 == rock_col) {
				if (king_row < 8 && rock_row < 8 && king_col > 1 && rock_col > 1) {
					king_row++;
					rock_row++;
					king_col--;
					rock_col--;
				}
			}
			else {
				if (king_row < 8 && king_col > 1) {
					king_row++;
					king_col--;
				}
			}
		}
		else if (move == "RB") {
			if (king_row - 1 == rock_row && king_col + 1 == rock_col) {
				if (king_row > 1 && rock_row > 1 && king_col < 8 && rock_col < 8) {
					king_row--;
					rock_row--;
					king_col++;
					rock_col++;
				}
			}
			else {
				if (king_row > 1 && king_col < 8) {
					king_row--;
					king_col++;
				}
			}
		}
		else if (move == "LB") {
			if (king_row - 1 == rock_row && king_col - 1 == rock_col) {
				if (king_row > 1 && rock_row > 1 && king_col > 1 && rock_col > 1) {
					king_row--;
					rock_row--;
					king_col--;
					rock_col--;
				}
			}
			else {
				if (king_row > 1 && king_col > 1) {
					king_row--;
					king_col--;
				}
			}
		}
	}
	char king_out = king_col + 'A' - 1;
	char rock_out = rock_col + 'A' - 1;
	cout << king_out << king_row << endl;
	cout << rock_out << rock_row;
	return 0;
}