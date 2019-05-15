//
// Created by 이승민 on 2019-05-14.
//

#include <iostream>

using namespace std;
int w, h;

void find_island(int *map[], int count, int x, int y){

    int num = 0;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int x_ = x + dx[i];
        int y_ = y + dy[i];

        if(x_ < 0 || x_ > h || y_ < 0 || y_ > w){
            continue;
        }
        else{
            if(map[x_][y_] == 1){
                map[x_][y_] = -1;
                num += 1;
                find_island(map, count, x, y);
            }
        }

    }

    if(num == 0){
        count += 1;
    }
}

int main(){

   // while(1){
         cin >> w >> h;

        if((w == 0) && (h == 0)){
            return 0;
        }

        int **map = new int*[h];
        for (int i = 0; i < h; ++i) {
            map[i] = new int[w];
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> map[i][j];
            }
        }

        int count = 0;
        find_island(map, count, 0, 0);
   // }

}