#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector <int> vec;
	int num;
	//cin >> num;
	num = 1000;
	int count = 0;
	
	for (int i = 0; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int temp = i + 10 * j;
			//int temp_ = 10 * i + j;

			if (temp <= num) {
				vec.push_back(temp);
			}

//			if (temp_ <= num) {
//				vec.push_back(temp_);
//			}
		 }
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 4; j++) {
			int temp__ = i + 10 * (i + j) + 100 * (i + 2 * j);

			if (temp__ <= num) {
				vec.push_back(temp__);
			}
		}
	}

	//cout << vec.size();
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	//sort(vec.begin(), vec.end());

	//for (int j = 0; j < vec.size(); j++) {
	//	cout << vec.at(j)<<endl;
	//}

	cout << vec.size()<<endl;
	return 0;
}