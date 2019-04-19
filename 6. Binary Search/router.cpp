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


	return 0;
}