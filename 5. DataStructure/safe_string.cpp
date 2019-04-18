//https://www.acmicpc.net/problem/4889

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> result;

vector <vector<int>> v;

void check_str(string str, int count) {
	vector<int> vv;
	for (int j = 0; j < str.size(); j++) {
		if (str.at(j) == '{') {
			vv.push_back(0);
		}
		else {

			vv.push_back(1);
		}
	}
	v.push_back(vv);

	//{}인 경우
	for (int j = 0; j < v[count].size() - 1; j++) {
		if( (v[count].at(j) == 0) && (v[count].at(j + 1) == 1)) {
			v[count].at(j) = -1;
			v[count].at(j + 1) = -1;
			j += 1;
		}
	}
	
	//{{}}인 경우
	for (int j = 0; j < v[count].size() - 1; j++) {
		if ((v[count].at(j) == 0) && (v[count].at(j + 1) == -1)) {
			int index = j;
			
			while (v[count].at(j + 1) == -1) {
				j += 1;
				if (j > v[count].size() - 2) {
					break;
				}

			}
						
			if (v[count].at(j) == 1) {
				v[count].at(j) = -1;
				v[count].at(index) = -1;
			}
		}
	}
}

int main() {

	string str;
	int count = 0;
	int num = 0;
	while (1) {
		cin >> str;
		if(str.find('-', 0) != -1){
			break;
		}

		num += 1;
		check_str(str, count);
		count += 1;
	}

	for (int i = 0; i < num; i++) {
		vector <int> temp;
		int many = 0;
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i].at(j) == -1) {
				many += 1;
			}
			else if (v[i].at(j) == 0) {
				temp.push_back(0);
			}
			else {
				temp.push_back(1);
			}
		}

		if (many == v[i].size()) {
			result.push_back(0);
		}
		else {
			for (int k = 0; k < temp.size(); k++) {
				if (k % 2 == 0) {
					if (temp.at(k) == 0) {
						many += 1;
					}
				}
				else {
					if (temp.at(k) == 1) {
						many += 1;
					}
				}
			}
			result.push_back(v[i].size() - many);
		}

	}

	for (int i = 0; i < result.size(); i++) {
		cout << i + 1 << ". " << result.at(i)<< endl;
	}

	return 0;
}