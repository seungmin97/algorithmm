//
// Created by 이승민 on 2019-05-07.
//

//입력예제 4 이해 못함

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

   int max_ = result[0];
    for (int i = 0; i < num; ++i) {
        if (i + v[i].first <= num) {
            result[i + v[i].first] = max(result[i + v[i].first], result[i] + v[i].second);
        }
    }
    for (int i = 0; i <= num; ++i) {
        max_ = max(max_, result[i]);
    }

    cout << max_;

    return 0;

}