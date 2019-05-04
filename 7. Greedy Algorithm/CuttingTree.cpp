//
// Created by 이승민 on 2019-05-03.
//

#include <iostream>
#include <climits>

//푸는중

using namespace std;

int l, k, c;
int *position;
int count;

bool check(int j){
    for (int i = 0; i < k; ++i) {
        if(j == position[i]) {
            count += 1;
            return true;
        }
    }
    return false;
}

void print(){

}

int main(){

    int max = INT_MAX;
    cin >> l >> k >> c;

    position = new int[k];
    for (int i = 0; i < k; ++i) {
        cin>>position[i];
    }
    count = 0;
    int length = 0;
    for (int j = 0; j < l; ++j) {
        if(check(j)){
            if(j < (l / 2)){
                length = l - j;
            }
            else{
                length = j;
            }
        }
    }

    return 0;
}