//
// Created by 이승민 on 2019-05-09.
//

//https://www.acmicpc.net/problem/1520

#include <iostream>
#include <string.h>
int map[501][501];
int visited[501][501];
int dp[501][501];

using namespace std;

int M, N;
int result = 0;

int move(int x, int y){


    if((x == M - 1) && (y == N - 1)){
        return 1;
    }

    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, -1, 0, 1};

    for (int k = 0; k < 4; ++k) {
        int x_ = x + dx[k];
        int y_ = y + dy[k];

        if (x_ < 0 || x_ >= M || y_ < 0 || y_ >= N) {
            continue;
        }
        else if (map[x][y] <= map[x_][y_]) {
            continue;
        }
        else if(visited[x_][y_] == -1){
            continue;
        }


         visited[x_][y_] == 0;
         dp[x_][y_] += move(x_, y_);

        }
    }
}

int main(){

    cin >> M >> N;

  for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < M; ++i) {
        memset(visited[i], -1, sizeof(int) * N);
    }

    move(0, 0);

    cout << dp[M-1][N-1];

    return 0;
}