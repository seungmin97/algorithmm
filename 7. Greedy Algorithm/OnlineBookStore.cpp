//
// Created by 이승민 on 2019-05-03.
//

// 틀림
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX INT_MAX

using namespace std;

class Book {
private:
    int price;
public:
    vector <pair<int, int>> vec;


    int calculate_price();
};

int Book::calculate_price() {

    for (int i = 0; i < vec.size(); ++i) {
        if(i == 0){
            price += vec[i].first;
        }
        else{
            price += vec[i].first - vec[i-1].second;
        }
    }
    return price;
}


bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

int main() {

    int num;
    cin >> num;
    int min;

    for (int k = 0; k < num; k++) {

        int store, book;
        cin >> book >> store;

        min = MAX;
        vector <Book> v(store);


        for (int i = 0; i < book; i++) {

            for (int j = 0; j < store; j++) {
                int temp1, temp2;
                cin >> temp1 >> temp2;
                v[j].vec.push_back(make_pair(temp1, temp2));
            }

        }

        for (int i = 0; i < store; ++i) {
            sort(v[i].vec.begin(), v[i].vec.end(), cmp);

            int result = v[i].calculate_price();
            if (min > result) {
                min = result;
            }

        }
    }

    cout<<min;

    return 0;
}