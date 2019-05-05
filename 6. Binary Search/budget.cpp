//
// Created by 이승민 on 2019-05-05.
//

//https://www.acmicpc.net/problem/2512

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int num;
    cin >> num;

    vector <int> v(num);

    int max = 0;
    for (int i = 0; i < num; i++) {
        cin >> v[i];

        if (v[i] > max) {
            max = v[i];
        }
    }

    int budget;
    cin >> budget;

    int left = 0;
    int right = max;
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < num; i++) {
            if (v[i] < mid) {
                sum += v[i];
            }
            else {
                sum += mid;
            }
        }

        if (sum <= budget) {
            left = mid + 1;
            result = mid;
        }
        else {
            right = mid - 1;
        }

    }

    cout << result<<endl;

    return 0;
}