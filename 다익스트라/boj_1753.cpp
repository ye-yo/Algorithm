#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000
#define MAX 20001

struct compare{
	bool operator()(pair<int, int>a, pair<int, int>b){
		return a.second > b.second; //큰 값을 먼저 정렬해서 작은 값을 가장 위로(인덱스로는 가장 앞의 인덱스0)
	}
};

int main(void){
    int V, E;
    vector<pair<int,int>> map[MAX];
    cin >> V >> E;
    int u,v,w,start;
    cin >> start;
    for(int i = 0; i< E; i++){
        cin >> u >> v >> w;
        map[u].push_back(make_pair(v,w));
    }
    int visited[MAX] = {0,};
    int dist[MAX];

    for(int i = 1; i<= V; i++){
        dist[i] = INF;
    }

    priority_queue <pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({start, 0});
    dist[start] = 0;
    while(!pq.empty()){
        int index = (pq.top()).first;
        pq.pop();
        visited[index] = 1;
        for(int j = 0; j< map[index].size(); j++){
            pair<int,int> next = map[index][j];
            int nextNode = next.first;
            if(visited[nextNode]) continue;
            int nextWeight = next.second;
            if(dist[nextNode] > dist[index] + nextWeight){
                dist[nextNode] = min(dist[nextNode], dist[index] + nextWeight);
                pq.push(next);
            }
        }
    }

    for(int i =1; i<= V; i++){
        if(dist[i] == INF){
            cout << "INF";
        }
        else cout << dist[i];
        cout <<"\n";
    }
    return 0;
}
