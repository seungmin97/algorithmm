#include <iostream>

using namespace std;

int time;
int alphabet[26] = { 0 };


void dfs(int x, int y, char **board, int num, int R, int C);


int main()
{
	int R, C;
	cin >> R >> C;

	char **board = new char*[R];

	for (int i = 0; i < R; i++) {
		board[i] = new char[C];
		
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	alphabet[(int)board[0][0] - 65] = 1;
	
	dfs(0, 0, board, 0, R, C);

	cout << time << endl;

	return 0;
}

void dfs(int x, int y, char **board, int num, int R, int C) {


	int direction_x[4] = { +1, 0, -1, 0 };
	int direction_y[4] = { 0, -1, 0, +1 };

	num += 1;

	for (int i = 0; i < 4; i++) {
		int x_ = x + direction_x[i];
		int y_ = y + direction_y[i];

		if ((x_ >= 0) && (x_ < R) && (y_ >= 0) && (y_ < C) && (alphabet[(int)board[x_][y_] - 65] == 0))
		{
			alphabet[(int)board[x_][y_] - 65] = 1;
			dfs(x_, y_, board, num, R, C);
			alphabet[(int)board[x_][y_] - 65] = 0;
		}
	}

	if (time < num) {
		time = num;
	}
}