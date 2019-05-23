//
// Created by 이승민 on 2019-05-22.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>


using namespace std;

int main(){

    string str;
    cin >> str;

    stack <char> s;
    char temp;
    vector <int> index;
    vector <pair<int, int>> v;
    for (int i = 0; i < str.length(); ++i) {

        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
          index.push_back(i);
        }
        else if(str[i] == '('){
            for (int j = i; j < str.length(); ++j) {
                if(str[j] == ')'){
                    v.push_back(make_pair(i, j));
                }
            }
            i = j + 1;
        }
    }

    for (int i = 0; i < v.size(); ++i) {

    }

    return 0;
}