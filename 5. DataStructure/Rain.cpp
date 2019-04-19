//https://www.acmicpc.net/problem/2094

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define TRUE 1
#define FALSE 0

vector <int> result;

void check(vector <pair<int, int>> v, int num) {
	int count = 0;
	for (int i = 0; i < num - 1; i++) {

		if (v[i].second > v[i + 1].second) {
			result.push_back(FALSE);
			break;
		}
		else {
			count += 1;
		}
	
	}
	if (count == num - 1) {

		result.push_back(TRUE);
	}
}
int main() {

	vector <pair<int, int>> v;

	int num;

 // 	while (1) {
 		cin >> num;
		for (int i = 0; i < num; i++) {
			int temp1, temp2;
			cin >> temp1 >> temp2;
			v.push_back(make_pair(temp1, temp2));
		
		}
		check(v, num);
//	}
	for (int i = 0; i < result.size(); i++) {
		if (result.at(i) == 0) {
			cout << "false" << endl;
		}
		else {
			cout << "true" << endl;
		}
	}
	return 0;
}