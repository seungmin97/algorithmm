#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {

	string str;
	int sum[4] = { 0 };
	int result = 0;
	int i, j;
	int temp, num, index, sum_index = -1;
	string str_ = { '\0' };

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		temp = 0;

		if ((str[i] >= '0') && (str[i] <= '9')) {
			str_[0] = str[i];
			sum_index += 1;

			if ((str[i + 1] >= '0') && (str[i + 1] <= '9')) {
				str_[1] = str[i + 1];
				i += 1;
			}
			num = stoi(str_);
		}
		else {
			if (str[i] == 'S') {
				if (str[i + 1] == '*') {
					if (sum_index >= 1) {
						sum[sum_index - 1] *= 2;
					}
					temp += pow(num, 1) * 2;
					i += 1;
				}
				else if (str[i + 1] == '#') {
					temp -= pow(num, 1) * 1;
					i += 1;
				}
				else {
					temp += pow(num, 1);
				}
			}
			else if (str[i] == 'D') {
				if (str[i + 1] == '*') {
					if (sum_index >= 1) {
						sum[sum_index - 1] *= 2;
					}
					temp += pow(num, 2) * 2;
					i += 1;
				}
				else if (str[i + 1] == '#') {
					temp -= pow(num, 2) * 1;
					i += 1;
				}
				else {
					temp += pow(num, 2);
				}
			}
			else if (str[i] == 'T') {
				if (str[i + 1] == '*') {
					if (sum_index >= 1) {
						sum[sum_index - 1] *= 2;
					}
					temp += pow(num, 3) * 2;
					i += 1;
				}
				else if (str[i + 1] == '#') {
					temp -= pow(num, 3) * 1;
					i += 1;
				}
				else {
					temp += pow(num, 3);
				}
			}
		}

		sum[sum_index] = temp;
	}

	for (i = 0; i < 3; i++) {
		result += sum[i];
	}

	cout << result << endl;

	return 0;
}