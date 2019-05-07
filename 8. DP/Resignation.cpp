//
// Created by 이승민 on 2019-05-07.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int num;
    cin>> num;

    vector <pair <int, int>> v(num);

    for (int i = 0; i < num; ++i){
        cin >> v[i].first >> v[i].second;
    }



    return 0;
}