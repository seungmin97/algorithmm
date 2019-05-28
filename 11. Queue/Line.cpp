//
// Created by 이승민 on 2019-05-27.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

class node{

public:
    vector <int> right;
    vector <int> left;
    int check_left(int *arr);
};

int node :: check_left(int *arr){

    int count = 0;
    for (int i = 0; i < left.size(); ++i) {
        if(arr[left[i]] == 1){
            count += 1;
        }
    }
    if(count == left.size()){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    int N, M;
    cin >> N >> M;

    int *arr = new int[N + 1];
    memset(arr, 0, sizeof(int) * (N + 1));

    vector <node> n(N + 1);

    queue <int> q;
    stack <int> s;
    for (int i = 0; i < M; ++i) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        n[temp1].right.push_back(temp2);
        n[temp2].left.push_back(temp1);
    }

    //첫번째 원소 구하기
    for (int i = 1; i <= N; ++i) {
        if(n[i].left.size() == 0) {
            q.push(i);
            arr[i] = 1;
        }
    }
    //  cout << q.front() << q.back() << q.size();

    int index = 1;
    while(q.size() != N){
        index = index % N;
        if(n[index].check_left(arr) && arr[index] == 0){
            q.push(index);
            arr[index] = 1;
        }
        index += 1;
    }

    while(q.size() != 0){
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}
