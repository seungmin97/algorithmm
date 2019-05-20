//
// Created by 이승민 on 2019-05-20.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
vector <string> v;
void check(string str){
    stack <char> s;
    for (int i = 0; i < str.length(); ++i) {
        if(s.empty()){
            if(str[i] == '('){
                s.push(str[i]);
            }
            else{
               v.push_back("NO");
               return;
            }
        }
        else{
            if(str[i] == ')'){
                if(s.top() == '(')
                    s.pop();
                else{
                    v.push_back("NO");
                    return;
                }
            }
            else{
                s.push(str[i]);
            }
        }
    }

    if(s.size() == 0){
        v.push_back("YES");
    }
    else{
        v.push_back("NO");
    }
}

int main(){

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        string str;
        cin >> str;

        check(str);
    }

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }

    return 0;
}