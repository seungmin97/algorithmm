//
// Created by 이승민 on 2019-05-13.
//

//시간초과
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int visited[20000] = {0};
int N, M;
queue <int> q;
queue <int> q_;

class node{
public:
    vector <int> v;
};

int bfs(vector <node> no){
    int temp = q.size();
    q_ = q;

    for (int i = 0; i < temp; ++i) {
        for (int j = 0; j < no[q.front()].v.size(); ++j) {
            if(visited[no[q.front()].v[j]] == 0){
                visited[no[q.front()].v[j]] = 1;
                q.push(no[q.front()].v[j]);
            }
        }
        q.pop();
    }
}

int main(){

    cin >> N >> M;
    vector <node> no(N + 1);

    for (int i = 0; i < M; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        no[n1].v.push_back(n2);
        no[n2].v.push_back(n1);

    }
    int count = 0;

    q.push(1);
    visited[1] = 1;

    while(q.size() != 0){
        count += 1;
        bfs(no);
    }

    int size = q_.size();
    int min = N;
    for (int i = 0; i < q_.size(); ++i) {
        if(min > q_.front()){
            min = q_.front();
        }
        q_.pop();
    }

    cout << min << ' ' << count - 1 << ' ' << size;

    return 0;
}