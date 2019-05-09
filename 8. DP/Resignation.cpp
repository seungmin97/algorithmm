//
// Created by 이승민 on 2019-05-07.
//

//https://www.acmicpc.net/problem/14501

//모르겠다ㅠ

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    int num;
    cin>> num;

    vector <pair <int, int>> v(num);

    int *result = new int[num + 1];

    for (int i = 0; i < num; ++i){
        cin >> v[i].first >> v[i].second;
        result[i] = 0;
    }
    result[num] = 0;

    int max_ = 0;
    for (int i = num - 1; i >= 0 ; --i) {
        int index = i + v[i].first;

    }

    for (int i = 1; i <= num; ++i) {
        max_ = max(max_, result[i]);
    }

    cout << max_;

    return 0;

}