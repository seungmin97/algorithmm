//
// Created by 이승민 on 2019-05-07.
//

//https://www.acmicpc.net/problem/1912

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int num;
    cin >> num;
    
    int *num_array = new int[num];
    int *result = new int[num];
    for(int i = 0; i < num; i++){
        cin >> num_array[i];
        result[i] = num_array[i];
    }

    for (int i = 1; i < num; ++i) {
        result[i] = max(result[i], result[i - 1] + num_array[i]);
    }

    int max_ = result[0];

    for (int i = 1; i < num; ++i) {
        max_ = max(max_, result[i]);
    }

    cout << max_;

    return 0;
}