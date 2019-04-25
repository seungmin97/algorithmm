//https://www.acmicpc.net/problem/13506

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	vector <string> v;
	string str;

	str = "fixprefixsuffix";
	//cin >> str;

	for (int i = 0; i < str.length() - 1; i++) {
		string temp = new string[i + 1];

		int index = 0;
		for (int j = str.length() - i - 1; j < str.length(); j++) {
			
			if (str[index] == str[j]) {
				temp[index] = str[index];
				index += 1;
				
			}
			else {
				break;
			}			
		}
		if (index == i + 1) {
			v.push_back(temp);
		}
	}

	return 0;
}