//
// Created by 이승민 on 2019-05-04.
//

//하는중
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string str;
    int count;

    while(1){
       count = 0;

       stack<char> s;
       // cin >> str;
       str = "{}{}";
        if(str.find('-') != -1)
        {
            return 0;
        }
        else{
            for (int i = 0; i < str.length(); ++i) {
                if(i == 0){
                    if(str[i] == '}'){
                        count += 1;
                        s.push('{');
                    }
                    else{
                        s.push(str[i]);
                    }
                }
                else{
                    if(str[i] == '{'){
                        s.push(('{'));
                    }
                    else {
                        s.top() == '{';
                        s.pop();
                    }
                }
            }
        }
    }
}
