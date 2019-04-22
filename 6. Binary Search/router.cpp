#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {

	vector <int> v;
	int num_router, num_home;

	cin >> num_home >> num_router;

	int temp;
	for (int i = 0; i < num_home; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	int left = 1;
	int right = v.at(num_home - 1);
	int num = 0;

	int start = 0;

	int size = (right - 1) / 2;

	while (size >= 1) {
		start = 0;
		num = 1;
		for (int i = 1; i < num_home; i++) {

			if (v.at(i) - v.at(start) >= size) {
				start = i;
				num++;
			}
		}

		if (num > num_router) {
			size += 1;
		}
		else if (num == num_router) {
			cout << num << endl ;
			return 0;
		}
		else {
			size -= 1;
		}
	}
	
	return 0;
}