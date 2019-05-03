//
// Created by 이승민 on 2019-05-03.
//

//https://www.acmicpc.net/problem/2217

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int num;
    cin >> num;

    vector <int> v(num);

    for (int i = 0; i < num; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < num; i++) {

        ans = max(ans, v[i] * (num - i));
    }

    cout << ans<<endl;
    return 0;
}