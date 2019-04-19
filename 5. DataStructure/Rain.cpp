#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {

	vector <pair<int, int>> v;

	int num;

	while (1) {
		cin >> num;
		for (int i = 0; i < num; i++) {
			int temp1, temp2;
			cin >> temp1 >> temp2;

			v.push(make_pair(temp1, temp2));
		}

	}

	return 0;
}