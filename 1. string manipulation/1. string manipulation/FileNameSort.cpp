#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

#define SIZE 1000

using namespace std;

class File {

public:
	string head;
	int num;
	string num_;
	int index;
	string tail;
	void divide(string str);
	int is_num(char a);
};

int File::is_num(char a) {
	if (((int)a >= 48) && ((int)a <= 57)) {
		return 1;
	}
	else {
		return 0;
	}
}

void File::divide(string str) {

	index = 0;
	while (!is_num(str[index])) {
		head = head +  str[index];
		index += 1;
	}

	while (is_num(str[index])) {
		num_ = num_ + str[index];
		index += 1;
	}

	num = stoi(num_);

	for(int j = index; j < str.size(); j++){
		tail = tail + str[j];
	}
	head.erase(remove_if(head.begin(), head.end(), isspace), head.end());
	tail.erase(remove_if(tail.begin(), tail.end(), isspace), tail.end());
}


int main() {

	int i, j;

//	//string *FILE;
//	string str;
///	cin >> str;
	int num = 0;

	vector<string> FileNames = { "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" };

	File *file = new File[FileNames.size()];

	for (i = 0; i < FileNames.size(); i++) {

		file[i].divide(FileNames[i]);
	}
	
	

	return 0;
}