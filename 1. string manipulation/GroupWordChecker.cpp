#include <iostream>
#include <string>

using namespace std;

int main() {

	int num = 0;
	int i, j;
	int result;

	cin >> num;

	result = num;
	string str;

	for (i = 0; i < num; i++){
		
		int alphabet[27] = { 0 };

		cin >> str;

		alphabet[(int)str[0] - 97] = 1;

		for (j = 1; j < str.length(); j++) {
	
		//	cout << (int)str[0];

			if (str[j] != str[j - 1]) {

				if (alphabet[(int)str[j] - 97] == 1) {
					result -= 1;
					break;
				}
				else {
					alphabet[(int)str[j] - 97] = 1;
				}
			}
		}
	}

	cout << result;
	return 0;

}