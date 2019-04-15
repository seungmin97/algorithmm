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

	void Detoxification();
};

int main() {

	int num;
	int loop = 0;
	cin >> loop;
	
	vector <security> v;

	string temp;
	for (int i = 0; i < loop; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> temp;
			v[i].v1.push_back(temp);
		}
		for (int j = 0; j < num; j++) {
			cin >> temp;
			v[i].v2.push_back(temp);
		}
		for (int j = 0; j < num; j++) {
			cin >> temp;
			v[i].v3.push_back(temp);
		}
	}

	

	return 0;
}