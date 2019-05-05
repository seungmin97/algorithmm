//
// Created by 이승민 on 2019-05-04.
//

//하는중
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

void print(){
    for (int i = 0; i < v.size(); ++i) {
        cout << i + 1 << ". " << v.at(i) << endl;
    }
}

int main() {

    string str;
    int count;

    while(1){
       count = 0;

       stack<char> s;
        cin >> str;
        if(str.find('-') != -1)
        {
            print();
            return 0;
        }
        else{
            for (int i = 0; i < str.length(); ++i) {
                //첫번째 값
                if(i == 0){
                    if(str[i] == '}'){
                        count += 1;
                        s.push('{');
                    }
                    else{
                        s.push(str[i]);
                    }
                }
                //나머지 값
                else{
                    if(str[i] == '{'){
                        s.push(('{'));
                    }
                    else{
                        if(s.top() == '{'){
                            s.pop();
                        }
                        else{
                            s.push('{');
                            count += 1;
                        }
                    }
                }
            }
        }
        count += s.size() / 2;
        v.push_back(count);
    }
}
