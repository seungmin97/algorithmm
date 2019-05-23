//
// Created by 이승민 on 2019-05-22.
//

#include <iostream>
#include <vector>
using namespace std;


int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first*b.second + b.first*c.second + c.first*a.second;
    op -= (a.second*b.first + b.second*c.first + c.second*a.first);
    if (op > 0)return 1;
    else if (op == 0)return 0;
    else return -1;
}

bool isIntersect(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y) {
    pair<int, int> a = x.first;
    pair<int, int> b = x.second;
    pair<int, int> c = y.first;
    pair<int, int> d = y.second;
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
     //   return c <= b&&a <= d;
    }

    if(ab <= 0 && cd <= 0){
        return false;
    }
    else{
        return true;
    }
}

int main(){

    int N;
    cin >> N;

    vector <pair<int , int>> v(N + 1);
    for (int i = 1; i <= N; ++i) {
        int temp;
        v.push_back(make_pair(i, temp));
    }

    int max = 0;
    int result = 0;

    for (int i = 1; i <= N; ++i) {

        int count = 0;
        for (int j = i - 1; j > 0 ; --j) {
            for (int k = i - 1; k > j; --k) {
                // isIntersect( pair<pair<int, int>, pair<int, int>> y)

                pair<pair<int, int>, pair<int, int>> x = make_pair(make_pair(k, 0), v[k]);
                pair<pair<int, int>, pair<int, int>> y = make_pair(v[i], v[j]);

                if(isIntersect(x, y)){
                    count += 1;
                }
            }
        }

        for (int j = i + 1; j <= N; ++j) {

            for (int k = i + 1; k < j; ++k) {
               // isIntersect( pair<pair<int, int>, pair<int, int>> y)

                pair<pair<int, int>, pair<int, int>> x = make_pair(make_pair(k, 0), v[k]);
                pair<pair<int, int>, pair<int, int>> y = make_pair(v[i], v[j]);

                if(isIntersect(x, y)){
                        count += 1;
                }
            }


        }

        if(count > max){
            max = count;
            result = v[i].second;
        }
    }

    cout << result;

    return 0;

}