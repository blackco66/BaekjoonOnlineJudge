#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string country[4];
    cin >> country[0] >> country[1] >> country[2] >> country[3];
    int cont[6][3];
    long double result[6][3];

    for (int i = 0; i < 6; i++) {
        string tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        cin >> result[i][0] >> result[i][1] >> result[i][2];
        for (int j = 0; j < 4; j++) {
            if (country[j] != tmp1) continue;
            for (int k = 0; k < 4; k++) {
                if (country[k] != tmp2) continue;
                cont[i][0] = j;
                cont[i][2] = k;
            }
        }
    }
    long double prop[6] = {0};
    for (int line1 = 0; line1 < 3; line1++) {
        for (int line2 = 0; line2 < 3; line2++) {
            for (int line3 = 0; line3 < 3; line3++) {
                for (int line4 = 0; line4 < 3; line4++) {
                    for (int line5 = 0; line5 < 3; line5++) {
                        for (int line6 = 0; line6 < 3; line6++) {
                            long double thisprop = result[0][line1] * result[1][line2];
                            thisprop *= result[2][line3] * result[3][line4];
                            thisprop *= result[4][line5] * result[5][line6];
                            if (thisprop == 0) continue;
                            int score[6] = {0};
                            if (line1 == 0 || line1 == 2) {
                                score[cont[0][line1]] += 3;
                            } else {
                                score[cont[0][0]] += 1;
                                score[cont[0][2]] += 1;
                            }
                            if (line2 == 0 || line2 == 2) {
                                score[cont[1][line2]] += 3;
                            } else {
                                score[cont[1][0]] += 1;
                                score[cont[1][2]] += 1;
                            }
                            if (line3 == 0 || line3 == 2) {
                                score[cont[2][line3]] += 3;
                            } else {
                                score[cont[2][0]] += 1;
                                score[cont[2][2]] += 1;
                            }
                            if (line4 == 0 || line4 == 2) {
                                score[cont[3][line4]] += 3;
                            } else {
                                score[cont[3][0]] += 1;
                                score[cont[3][2]] += 1;
                            }
                            if (line5 == 0 || line5 == 2) {
                                score[cont[4][line5]] += 3;
                            } else {
                                score[cont[4][0]] += 1;
                                score[cont[4][2]] += 1;
                            }
                            if (line6 == 0 || line6 == 2) {
                                score[cont[5][line6]] += 3;
                            } else {
                                score[cont[5][0]] += 1;
                                score[cont[5][2]] += 1;
                            }
                            int firstplace = 0;
                            for (int i = 1; i < 4; i++) {
                                if (score[i] > score[firstplace]) firstplace = i;
                            }
                            int secondplace = -1;
                            for (int i = 0; i < 4; i++) {
                                if (i == firstplace) continue;
                                if (secondplace == -1) secondplace = i;
                                if (score[i] > score[secondplace]) secondplace = i;
                            }
                            int thirdplace = -1;
                            for (int i = 0; i < 4; i++) {
                                if (i == firstplace || i == secondplace) continue;
                                if (thirdplace == -1) thirdplace = i;
                                if (score[i] > score[thirdplace]) thirdplace = i;
                            }
                            int fourthplace = -1;
                            for (int i = 0; i < 4; i++) {
                                if (i == firstplace || i == secondplace || i == thirdplace) continue;
                                if (fourthplace == -1) fourthplace = i;
                            }
                            if (score[secondplace] != score[thirdplace]) {
                                prop[firstplace] += thisprop;
                                prop[secondplace] += thisprop;
                            } else {
                                if (score[firstplace] != score[secondplace]) {
                                    if (score[thirdplace] != score[fourthplace]) {
                                        prop[firstplace] += thisprop;
                                        prop[secondplace] += thisprop / 2;
                                        prop[thirdplace] += thisprop / 2;
                                    } else {
                                        prop[firstplace] += thisprop;
                                        prop[secondplace] += thisprop / 3;
                                        prop[thirdplace] += thisprop / 3;
                                        prop[fourthplace] += thisprop / 3;
                                    }
                                } else {
                                    if (score[thirdplace] != score[fourthplace]) {
                                        prop[firstplace] += thisprop / 3 * 2;
                                        prop[secondplace] += thisprop / 3 * 2;
                                        prop[thirdplace] += thisprop / 3 * 2;
                                    } else {
                                        prop[firstplace] += thisprop / 4 * 2;
                                        prop[secondplace] += thisprop / 4 * 2;
                                        prop[thirdplace] += thisprop / 4 * 2;
                                        prop[fourthplace] += thisprop / 4 * 2;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << prop[i] << endl;
    }
    return 0;
}