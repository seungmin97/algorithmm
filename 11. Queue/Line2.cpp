//
// Created by 이승민 on 2019-05-28.
//

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;

    vector <vector <int>> vt;
    vt.resize(N + 1);

    int *in = new int[N + 1];
    memset(in, 0, sizeof(int) * (N + 1));

    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        vt[temp1].push_back(temp2);
        in[temp2]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= N; i++) {
        if (!in[i])
            pq.push(-i);
    }

    while (pq.size()) {
        int here = -pq.top();
        pq.pop();
        cout << here << ' ';

        for (int there : vt[here]) {
            in[there]--;
            if (!in[there])
                pq.push(-there);
        }
    }


    return 0;
}