#include <iostream>

using namespace std;


class BFS{
	
public:
	int left;
	int middle;
	int right;
	int check = -1;
	int level = 0;
	int count = 0;
	int *bfs;

	void make_graph(int seek);

};

void BFS::make_graph(int temp) {
	check += 1;
	
	left = temp - 1;
	middle = temp + 1;
	right = 2 * temp;

	bfs[count++] = temp - 1;
	bfs[count++] = temp + 1;
	bfs[count++] = 2 * temp;

	if (check % 3 == 0) {
		make_graph(left);
		//check += 1;
	}
	else if (check % 3 == 1) {
		make_graph(middle);
		//check += 1;
	}
	else {
		make_graph(right);
	}
}

int main() {

	BFS bfs_;

	int hide, seek;
	int i, j, k;

	//cin >> seek >> hide;
	seek = 5;
	hide = 17;

	bfs_.bfs = new int[hide - seek];

	bfs_.make_graph(seek);
	
	return 0;
}

