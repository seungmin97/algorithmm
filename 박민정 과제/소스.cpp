#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>


using namespace std;

ofstream outFIle("output.txt");

class CDivision {
public:
	char *name;
	int NstaffD;
	double sum , ave;
	int *IDStaffD;
	int *Salary;

	void AllocMemD(int NstaffD);
	void Calsum(int *temp);
	void CalAve();

	~CDivision() {

	}
};

class CCompany {
public:
	//ifstream *inFile;
	ifstream *in;
	ofstream *outFile;
	char name[20];
	int Nstaff;
	int Ndiv;
	int count = 0;
	double sum, ave;
	double *SumDiv, *AveDiv;

	CDivision *Division;
	CCompany(char *p, int num) {
		strcpy_s(name, p);
		Ndiv = num;
	}

	~CCompany() {
	}
	void processData(int* temp);
	void AllocMemC();

};

void CDivision::Calsum(int *temp) {
	sum = 0;
	for (int k = 0; k < NstaffD; k++) {
		sum += temp[k];
	}
}


void CDivision::CalAve() {
	ave = sum / NstaffD;
}

void CCompany::processData(int *temp) {

	Division->Calsum(temp);
	Division->CalAve();

	sum = Division->sum;
	ave = Division->ave;
	cout<< sum << "\t" << ave << endl;
	outFIle << ": sum = " << sum << "\t ave = "<<ave << endl;
}

void CDivision::AllocMemD(int NstaffD) {
	IDStaffD = new int[NstaffD];
	Salary = new int[NstaffD];
}

void CCompany::AllocMemC() {

	int linenum = 0;


	ifstream inFile("input.txt");

	char buf[200];
	char *tok;
	char *buf_;

	while (!inFile.eof()) {

		if (linenum == 0) {
			inFile.getline(buf, 200);
			tok = strtok_s(buf, ":", &buf_);
			char* ltrim(buf_);	//공백제거
			strcpy_s(name, buf_);	//company name 저장
			linenum += 1;
		}
		else if (linenum == 1) {
			inFile.getline(buf, 200);
			tok = strtok_s(buf, ":", &buf_);
			Ndiv = atoi(buf_);	//숫자로 변환
			Division = new CDivision[Ndiv];	//숫자만큼 division 동적할당
			linenum += 1;
		}
		else if (linenum == 2) {
			inFile.getline(buf, 200);
			linenum += 1;
			continue;
		}
		else {

			for (int i = 0; i < Ndiv; i++) {
				//Division name 저장
				inFile.getline(buf, 200);
				tok = strtok_s(buf, ":", &buf_);
				char* ltrim(buf_);	//공백제거
				tok = strtok_s(buf_, ":", &tok);
				cout << buf_;
				Division[i].name = buf_;
				outFIle << Division[i].name;
				
				//staff 명수 저장
				inFile.getline(buf, 200);
				tok = strtok_s(buf, ":", &buf_);
				Nstaff = atoi(buf_);
				Division[i].NstaffD = Nstaff;
				Division[i].AllocMemD(Nstaff);
				
				//SumDiv와 AveDiv 동적할당
				SumDiv = new double[Nstaff];
				AveDiv = new double[Nstaff];

				//staff명수만큼 for문 돌면서 *IDStaffD랑 *Salary에 저장
				for (int j = 0; j < Division[i].NstaffD; j++) {
					inFile.getline(buf, 200);
					//	char *ffff;
					char *temp = strtok_s(buf, " ", &buf_);
					Division[i].IDStaffD[j] = atoi(temp);
					Division[i].Salary[j] = atoi(buf_);
				}

				//sum과 ave 계산
				processData(Division[i].Salary);

				SumDiv[i] = sum;
				AveDiv[i] = ave;
			}
		}
	}
}

int main(CCompany company) {

	company.AllocMemC();

	return 0;
}