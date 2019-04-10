#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> sum1, sum2;

int main() {

	int num;
	cin >> num;
	vector<long> a;
	vector<long> b;
	vector<long> c;
	vector<long> d;

	long aa, bb, cc, dd;
	long long result = 0;
	int sum = 0;
	long long sum1_, sum2_;

	for (int i = 0; i < num; i++) {
		cin >> aa >> bb >> cc >> dd;
		a.push_back(aa);
		b.push_back(bb);
		c.push_back(cc);
		d.push_back(dd);
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			sum1_ = a.at(i) + b.at(j);
			sum2_ = c.at(i) + d.at(j);
			sum1.push_back(sum1_);
			sum2.push_back(sum2_);
		}
	}

	sort(sum2.begin(), sum2.end());
	
	//sum2에 같은 값이 여러개 있을 경우 갯수 count
	vector<pair<long long, int>> check;
	for (int i = 0; i < sum2.size(); i++) {
			if (sum2.at(i) == sum2.at(i + 1)) {
				int j = 1;

				while ((sum2.at(i) == sum2.at(i + j)) &&  ((i + j) != (sum2.size() - 1)))  {
					j += 1;
				}
				if (j == sum2.size() - 1) {
					check.push_back(make_pair(sum2.at(i), j + 1));

				}
				else {
					check.push_back(make_pair(sum2.at(i), j));
				}
				
				i = i + j;

				if (i < sum2.size()) {
					break;
				}
			}
	}


	for (int i = 0; i < sum1.size(); i++) {
		long long temp = sum1.at(i) * (-1);

		if (binary_search(sum2.begin(), sum2.end(), temp))
		{
			int mul = 1;
			for (int h = 0; h < check.size(); h++) {
				if (check[h].first == temp) {
					mul = check[h].second;
					break;
				}
			}
			//sum2에 같은 값이 처리
			result += 1 * mul;
		}

	}
	cout << result << endl;
	return 0;
}