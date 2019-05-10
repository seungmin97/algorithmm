//
// Created by 이승민 on 2019-05-09.
//

//https://www.acmicpc.net/problem/1520

//dp를 어떻게??
#include <iostream>

using namespace std;

int M, N;
int result = 0;

void move(int **map, int x, int y, int count){
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, -1, 0, 1};

    if(count == M + N - 2){
        result += 1;
    }

    for (int k = 0; k < 4; ++k) {
        int x_ = x + dx[k];
        int y_ = y + dy[k];

        if (x_ < 0 || x_ >= M || y_ < 0 || y_ >= N) {
            continue;
        }
        else if(map[x][y] <= map[x_][y_]){
            continue;
        }

        move(map, x_, y_, count + 1);

    }
}

int main(){

    cin >> M >> N;

    int **map = new int*[M];
    for (int i = 0; i < M; ++i) {
        map[i] = new int[N];
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    move(map, 0, 0, 0);

    cout << result;

    return 0;
}