//https://www.acmicpc.net/problem/1654

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline long long cut_lan(vector <int> v, long long mid) {

	int temp = 0;;
	for (int i = 0; i < v.size(); i++) {

		temp += v[i] / mid;
	}
	return temp;
}

int main() {

	//num : 랜선 갯수, count : 필요한 랜선 갯수
	int num, count;
	cin >> num >> count;

	vector <int> v;
	int max_ = 0;
	for (int i = 0; i < num; i++) {
		int var;
		cin >> var;
		v.push_back(var);
		max_ = max(v[i], max_);
	}

	long long left = 1;
	int result = 0;
	long long right = max_;
	while (left <= right) {
		long long mid = (left + right) / 2;

		int temp = cut_lan(v, mid);

		if (temp >= count) {
			left = mid + 1;
			result = mid;
		}
		else {
			right = mid - 1;
		}
	}

	cout << result << endl;

	return 0;
}