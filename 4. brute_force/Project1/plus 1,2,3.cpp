#include <iostream>
#include <vector>

using namespace std;

vector <int> vec(12, 0);

void make_result(int i) {


	for (int j = 1; j <= 3; j++) {
		if ((i - j) >= 0)
		{
			vec.at(i) += vec.at(i - j);
		}
	}
}


int main() {

	vector <int> input;
	int temp;
	
	vec.at(1) = 1;
	vec.at(2) = 1;
	vec.at(3) = 1;
	
	int num;
	cin >> num;

	for (int i = 1; i < 11; i++) {
		make_result(i);
	}

	for (int k = 0; k < num; k++){
		cin >> temp;
		input.push_back(temp);
	}

	for (int j = 0; j < input.size(); j++) {
		cout << vec.at(input.at(j)) << endl;
	}
	
	return 0;
}