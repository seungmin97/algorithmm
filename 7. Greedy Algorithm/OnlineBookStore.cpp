//https://algospot.com/judge/problem/read/BOOKSTORE

#include <iostream>
#include <vector>

using namespace std;

class Book {
public:
	vector <pair<int, int>> vec;
	
	int price() {

	}
};

int main() {

	int num;
	cin >> num;
	
	
	for (int k = 0; k < num; k++) {
				
		int store, book;
		cin >> store >> book;
		
		int min = INT_MAX;
		vector <Book> v(store);

		for (int i = 0; i < store; i++) {
				
			for (int j = 0; j < book; j++) {
				int temp1, temp2;
				cin >> temp1 >> temp2;
				v[i].vec.push_back(make_pair(temp1, temp2));
			}
			int result = v[i].price;
			if (min > result) {
				min = result;
			}
		}

	}
	
	return 0;
}