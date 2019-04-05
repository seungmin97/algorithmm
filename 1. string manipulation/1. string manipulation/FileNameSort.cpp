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
	string str;
	string num_;
	int index;
	string tail;
	File(string str);

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

File::File(string str) {

	this->str = str;

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



bool cmp(const File &u, const File &v) {
	if (u.head == v.head) {
		return u.num < v.num;
	}
	else return u.head < v.head;
}

int main() {

	int i, j;

	int num = 0;

	vector<string> FileNames = { "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" };

	vector<File> file;

	for (int i = 0; i < FileNames.size(); i++) {
		file.push_back(File(FileNames[i]));
	}

	sort(file.begin(), file.end(), cmp);
	
	for (int i = 0; i < file.size(); i++) {
		cout << file[i].str << endl;
	}

	return 0;
}