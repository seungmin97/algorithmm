//
// Created by 이승민 on 2019-05-03.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX INT_MAX

using namespace std;

class Book {
private:
    int price;
    int remain;
public:
    vector <pair<int, int>> vec;

    Book(){
        this->price = 0;
        this->remain = 0;
    }

    int calculate_price();
};

int Book::calculate_price() {

    for (int i = 0; i < vec.size(); ++i) {

        if(i == 0){
            price += vec[i].first;
        }
        else {
            if (vec[i - 1].second <= vec[i].first) {
                int temp = 0;
                temp = vec[i].first - vec[i-1].second;

                if(remain != 0){
                    if(temp > remain){
                        price += temp - remain;
                        remain = 0;
                    }
                    else{
                        remain -= temp;
                    }
                }
                else{
                    price += temp;
                }

            }
            else{
                remain += vec[i-1].second - vec[i].first;
            }
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

//        min = MAX;
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

            if(i == 0){
                min = result;
            }
            else if (min > result) {
                min = result;
            }

        }
        cout << min << endl;
    }
    return 0;
}