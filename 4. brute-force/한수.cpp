#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	//321
	//46
	//11
	//64

	int num;
	//num = 1000;
	int count = 0;
	
	cin >> num;

	if (num < 100) {
		cout << num<<endl;
		return 0;
	}
	else {
		count = 99;
		for (int i = 100; i <= num; i++) {
			string temp = to_string(i);
			int dif1 = (int)temp.at(1) - (int)temp.at(0);
			int dif2 = (int)temp.at(2) - (int)temp.at(1);
			if (dif2 == dif1) {
				count += 1;
			}
		}
	}

	cout << count << endl;
	return 0;
}