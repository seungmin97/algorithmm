//https://www.acmicpc.net/problem/9322

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class security{
public:
	vector <string> v1;
	vector <string> v2;
	vector <string> v3;
	vector <string> v4;
	
	security(vector <string> v1, vector <string> v2, vector <string> v3, int size);
	int size;
	vector <pair<int, int>> v1_index;

	void check();
	void Detoxification();
};

security::security(vector <string> v1, vector <string> v2, vector <string> v3, int size) {
	this->v1 = v1;
	this->v2 = v2;
	this->v3 = v3;
	this->size = size;
}

void security::check() {

	for (int j = 0; j < size; j++) {
		for (int k = 0; k <size; k++) {
			if (v1.at(j).compare(v2.at(k)) == 0) {
				v1_index.push_back(make_pair(k, j));
			}
		}
	}
	sort(v1_index.begin(), v1_index.end());
}

void security::Detoxification() {

	for (int j = 0; j < size; j++) {
		v4.push_back(v3.at(v1_index[j].second));
	}

	for (int j = 0; j < size; j++) {
		cout << v4.at(j)<< " ";
	}
	cout << endl;
}

int main() {

	int num;
	int loop = 0;
	cin >> loop;
	
	vector <security> v;
	string temp;
	for (int i = 0; i < loop; i++) {
		cin >> num;
		vector <string> v1_;
		vector <string> v2_;
		vector <string> v3_;

		for (int j = 0; j < num; j++) {
			cin >> temp;
			v1_.push_back(temp);
		}
		for (int j = 0; j < num; j++) {
			cin >> temp;
			v2_.push_back(temp);
		}
		for (int j = 0; j < num; j++) {
			cin >> temp;
			v3_.push_back(temp);
		}
		v.push_back(security(v1_, v2_, v3_, num));
	}

	for (int i = 0; i < loop; i++) {
		v[i].check();
		v[i].Detoxification();
	}
	
	return 0;
}