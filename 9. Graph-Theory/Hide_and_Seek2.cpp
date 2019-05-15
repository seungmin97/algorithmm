//
// Created by 이승민 on 2019-05-14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

vector <int> result;    //터미널 노드 index

void bfs(int start, vector <int> graph[], bool check[], int distance[]){

    queue <int> q;
    q.push(start);
    check[start] = true;

    while(!q.empty()){
        int tmp = q.front();
         for (int i = 0; i < graph[tmp].size(); ++i) {
            if(check[graph[tmp][i]] == false){
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true;
                distance[graph[tmp][i]] = distance[tmp] + 1;
            }
        }
        q.pop();
    }
}

int main(){

    int N, M;
    cin >> N >> M;

    vector <int> graph[N + 1];
    int *distance = new int[N + 1];
    memset(distance, 0, sizeof(int) * (N + 1));
    bool check[N + 1];
    fill(check, check + N + 1, false);

    for (int i = 0; i < M; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(1, graph, check, distance);

    int index = 0;
    int num = 0;
    int max = distance[0];
    for (int i = 1; i < N + 1; ++i) {
        if(distance[i] > max){
            max = distance[i];
            num = 1;
            index = i;
        }
        else if(distance[i] == max){
            num += 1;
        }
    }

    cout << index << ' ' << max << ' ' << num;

    return 0;
}