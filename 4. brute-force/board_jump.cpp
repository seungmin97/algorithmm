#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 5

using namespace std;
vector <int> vv;
int board[SIZE][SIZE];

void get_number(int temp, int count, int x, int y) {

	if (count == 6) {
		vv.push_back(temp);
		return;
	}

	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

	for (int k = 0; k < 4; k++) {
		int x_ = x + dx[k];
		int y_ = y + dy[k];

		if (x_ < 0 || x_ >= SIZE || y_ < 0 || y_ >= SIZE) {
			continue;
		}
		get_number(temp * 10 + board[x_][y_], count + 1, x_, y_);
	}
}

int main() {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			get_number(board[i][j], 1, i, j);
		}
	}

	sort(vv.begin(), vv.end());
	vv.erase(unique(vv.begin(), vv.end()), vv.end());

	cout << vv.size() << endl;

	return 0;
}