//
// Created by 이승민 on 2019-05-15.
//

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;

int dfs(char *map[], int i, int count,int *visited, int result){

    visited[i] = 1;
    //int *map[], int i, int count, int num
    count += 1;
    if(count > 2){
        //num += 1;
        return 1;
    }

    for (int j = 0; j < N; ++j) {
        if((map[i][j] == 'Y') && (visited[j] == 0)){
            result += 1;
            visited[j] = 1;
            result += dfs(map, j, count, visited, result);
        }
    }

}

int main(){
    cin >> N;

    int *result = new int[N];
    char **map = new char*[N];
    for (int i = 0; i < N; ++i) {
        map[i] = new char[N];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    int *visited = new int[N];
    memset(visited, 0, sizeof(N));

    int max_;
    for (int i = 0; i < N; ++i) {
       // int num = 0;
       // int count = 0;
        if(i == 0){
            max_ = dfs(map, i, 0, visited, result[i]);
            //max_ =  dfs(map, i, 0, 0);
        }
        else{
            max_ = max(max_, dfs(map, i, 0, visited, result[i]));
            //max_ = max(max_, dfs(map, i, 0, 0));
        }
    }

    cout << max_;
}