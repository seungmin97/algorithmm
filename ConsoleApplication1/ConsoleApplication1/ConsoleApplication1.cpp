#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class CDivision {
public:
	char *name;
	int NstaffD;
	double sum, ave;
	int *IDStaffD;
	int *Salary;

	void AllocMemD(int temp);
	int Calsum();
	int CalAve();

	~CDivision() {

	}
};

class CCompany {
public:
	ifstream *input_file;
	ofstream *output_file;
	char name[10];
	int Nstaff;
	int Ndiv;
	double sum, ave;
	double *SumDiv, *AveDiv;

	CDivision *Division;
	CCompany(char *p, int num) {
		strcpy_s(name, p);
		Ndiv = num;
	}
	
	~CCompany() {
	}

	void AllocMemC();

};

void CCompany::AllocMemC() {

	int linenum = 0;

	input_file->open("input.txt");
	char buf[200];
	char *tok;
	char *buf_;
	int num = 0;
	if (input_file->is_open()) {
		while (!input_file->is_open()) {
			
			if (linenum == 0) {
				input_file->getline(buf, 200);
				tok = strtok_s(buf, ":", &buf_);
				char* ltrim(buf_);	//공백제거
				strcpy_s(name, buf_);	//company name 저장
				linenum += 1;
			}
			else if (linenum == 1) {
				input_file->getline(buf, 200);
				tok = strtok_s(buf, ":", &buf_);
				Ndiv = atoi(buf_);	//숫자로 변환
				Division = new CDivision[Ndiv];	//숫자만큼 division 동적할당
				linenum += 1;
			}
			else if (linenum == 2) {
				input_file->getline(buf, 200);	
				linenum += 1;
				continue;
			}
			else {

				for (int i = 0; i < Ndiv; i++) {
					input_file->getline(buf, 200);
					tok = strtok_s(buf, ":", &buf_);
					char* ltrim(buf_);	//공백제거
					Division[num].name = buf_;
					input_file->getline(buf, 200);
					Division[num].NstaffD = atoi(buf_);
				
					Division->AllocMemD(4);
					for (int j = 0; j < Division[num].NstaffD; j++) {
						
						input_file->getline(buf, 200);

					}
				
				}
			}


		}
	}
}

int main() {

	char aaa[20] = "1001 300.0";

	char *ffff;
	char *temp = strtok_s(aaa, " ", &ffff);
	int a = atoi(temp);

	cout << a<<endl << ffff;

	return 0;
}