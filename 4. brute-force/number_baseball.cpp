#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BaseBall {
public:
	string num;
	int strike;
	int ball;

	BaseBall(string num, int strike, int ball);
};

BaseBall::BaseBall(string num, int strike, int ball) {
	this->num = num;
	this->strike = strike;
	this->ball = ball;
}

int check_i(string temp) {
	for (int aa = 0; aa < 3; aa++) {
		if (temp.at(aa) == '0') {
			return 0;
		}
	}

	if ((temp.at(0) == temp.at(1)) || (temp.at(0) == temp.at(2)) || (temp.at(1) == temp.at(2))) {
		return 0;
	}
}

int main() {

	int result = 0;
	int check = 0;
	vector <BaseBall> baseball;
	
	int count;
	cin >> count;
	
	string num;
	int strike;
	int ball;

	for (int i = 0; i < count; i++) {
		cin >> num >> strike >> ball;
		baseball.push_back(BaseBall(num, strike, ball));
	}

	for (int i = 123; i <= 987; i++) {
		string temp = to_string(i);
		if (check_i(temp)) {

			for (int j = 0; j < baseball.size(); j++) {
				num = baseball.at(j).num;

				strike = 0;
				ball = 0;

				for (int k = 0; k < 3; k++) {
					if (num.at(k) == temp.at(k)) {
						strike += 1;
					}
					else {
						for (int h = 0; h < 3; h++) {
							if (num.at(k) == temp.at(h)) {
								ball += 1;
							}
						}
					}
				}

				if ((baseball.at(j).strike == strike) && (baseball.at(j).ball == ball)) {
					check += 1;
				}
				else {
					break;
				}
			}

			if (check == count) {
				result += 1;
			}

			check = 0;
		}
	}

	cout << result << endl;
	return 0;
}