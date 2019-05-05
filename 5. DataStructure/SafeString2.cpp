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

        //str에 -가 있는 경우
        if(str.find('-') != -1)
        {
            print();
            return 0;
        }
        else{
            for (int i = 0; i < str.length(); ++i) {
                //첫번째 값은 무조건 {가 와야 하기 때문에 아닌 경우 count갯수 증가시키고 stack에 { push

                if(s.size() == 0){
                    if(str[i] == '{'){
                        s.push(str[i]);
                    }
                    else{
                        s.push('{');
                        count += 1;
                    }
                }
                else{
                    if(str[i] == '}'){
                        if(s.top() == '{'){
                            s.pop();
                        }
                        else{
                            s.push('{');
                            count += 1;
                        }

                    }
                    else{
                        s.push(str[i]);
                    }

                }
            }
        }
        //{{{}{}
        //stack에 남아있는것은 다 {이기 때문에 그거의 반은 바껴야 함
        //그래서 size의 반을 바꿔야 함
        count += s.size() / 2;
        v.push_back(count);
    }
}
