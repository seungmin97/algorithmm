//메모리초과

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


class BFS{
	
public:
	int *bfs;
	int length;

	void make_graph(int *before_bfs, int *b, int length);

};

void BFS::make_graph(int *before_bfs, int *bfs, int length) {
	
	int count = 0;

	for (int j = 0; j < length; j++) {
		bfs[count++] = before_bfs[j] - 1;
		bfs[count++] = before_bfs[j] + 1;
		bfs[count++] = before_bfs[j] * 2;
	}
}

int main() {

	BFS *bfs_;

	int hide, seek;
	int i = 0, j, k;

	cin >> seek >> hide;
	
	bfs_ = new BFS[hide - seek];

	while(1){	
		
		if (i == 0) {
			bfs_[i].bfs = new int[1];
			bfs_[i].length = 1;
			bfs_[i].bfs[0] = seek;
		}
		else {
			int mul = pow(3, i - 1);
			bfs_[i].length = 3 * mul;
			bfs_[i].bfs = new int[3 * mul];
			bfs_[i].make_graph(bfs_[i-1].bfs, bfs_[i].bfs, bfs_[i - 1].length);

			for (k = 0; k < bfs_[i].length; k++) {
				if (bfs_[i].bfs[k] == hide) {
					cout << i << "초" << endl;
					return 0;
				}
			}
		}
		i += 1;
	}
	return 0;
}

