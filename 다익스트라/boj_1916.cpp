#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

int main(void){
    int N,M;
    vector<pair<int,int>> arr[1001];
    cin >> N >> M;
    int u,v,w,start,end;
    for(int i = 0; i< M; i++){
        cin >> u >> v >> w;
        arr[u].push_back({w,v}); 
    }
    cin >> start >> end;
    int dist[1001];
     for(int i = 1; i<= N; i++){
        dist[i] = INF;
    }

    int visited[1001] = {0,};

    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; 
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int currentNode = pq.top().second;
        int currentCost = pq.top().first;
        pq.pop();
        if(visited[currentNode]) continue;
        visited[currentNode] = 1;
        for(int i = 0; i< arr[currentNode].size(); i++){
            pair<int,int> next = arr[currentNode][i];
            int nextNode = next.second;
            int nextCost = next.first;
            if(dist[nextNode] > currentCost + nextCost){
                dist[nextNode] = currentCost + nextCost;
                pq.push({dist[nextNode],nextNode,});
            }
        }
    }

    cout << dist[end];
    return 0;
}