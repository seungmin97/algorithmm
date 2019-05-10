//
// Created by 이승민 on 2019-05-10.
//

//https://www.acmicpc.net/problem/2169

//빡쳐
#include <iostream>
#include <algorithm>

using namespace std;
int map[1002][1002];
int result[1002][1002] = {0};
int N, M;

void move_robot(int x, int y){

    int visited[1002][1002] = {0};
    //아래, 왼쪽, 오른
  int dx[4] = {1, 0, 0};
  int dy[4] = {0, -1, 1};

    for (int i = 0; i < 3; ++i) {

        int x_ = x + dx[i];
        int y_ = y + dy[i];

        if (x_ < 1 || x_ > N || y_ < 1 || y_ > M) {
            continue;
        }

        result[x_][y_] = max(result[x_][y_], result[x][y] + map[x_][y_]);
        move_robot(x_, y_);

    }
}

int main(){

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> map[i][j];
            result[i][j] = map[i][j];
        }
    }

    move_robot(1, 1);

        return 0;
}