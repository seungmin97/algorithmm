#include <iostream>
#include <fstream>

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
	CCompany(char *p, int num);

	void AllocMemC();

};

void CCompany::AllocMemC() {
	
	input_file->open("input.txt");
	
	char buf[200];
	char *tok;

	if (input_file->is_open()) {
		while (!input_file->is_open()) {
			input_file->getline(buf, 200);
		//	tok = strtok(buf, ":");

		}
	}

}

int main() {

	char temp[20]=  "name : seungmin";

	char *tok;

	tok = strtok_s(temp, ":", &tok);
	cout << tok;

	return 0;
}