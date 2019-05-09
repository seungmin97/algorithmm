//
// Created by 이승민 on 2019-05-07.
//

//https://www.acmicpc.net/problem/2294

#include <iostream>
#include <algorithm>
#include <climits>

#define Max 10001

using namespace std;

int main(){

    int n, k;

    cin >> n >> k;

    int *coin = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }
    sort(coin, coin + n);

    int *temp = new int[k + 1];

    for (int m = 1; m <= k; ++m) {
        temp[m] = Max;
    }

    temp[0] = 0;

    for (int l = 0; l < n; ++l) {
        for (int i = coin[l]; i <= k; ++i) {
            temp[i] = min(temp[i], temp[i - coin[l]] + 1);
        }
     }


    if(temp[k] != Max) {
        cout << temp[k];
    }
    else{
        cout << -1;
    }

    return 0;
}