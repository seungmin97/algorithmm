//
// Created by 이승민 on 2019-05-07.
//

#include <iostream>
#include <algorithm>

//시간초과
using namespace std;

int main(){

    int num;
    cin >> num;
    int min_;

    int *num_array = new int[num];
    for(int i = 0; i < num; i++){
        cin >> num_array[i];

        if(i != 0){
            min_ = min(num_array[i], num_array[i - 1]);
        }
    }

    int max_ = min_;

    for (int i = 0; i < num; ++i) {
        int sum = 0;
        for (int j = i; j < num; ++j) {
            sum += num_array[j];

            max_ = max(sum, max_);
        }
    }

    cout << max_;

    return 0;
}