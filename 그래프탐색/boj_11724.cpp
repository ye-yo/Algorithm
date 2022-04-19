#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(void){
    int N, M;
    cin >> N >> M;
    vector<int> arr[N + 1];
    queue<int> q;
    vector<int> visited(N+1,0);
    int u,v;
    for(int i = 0; i< M; i++){
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int cnt = 0;
    for(int i =1; i<= N; i++){
        if(visited[i]) continue;
        cnt++;
        q.push(i);
        while(!q.empty()){
            int current = q.front();
            q.pop();
            if(visited[current]) continue;
            visited[current] = 1;
            for(int i = 0; i<arr[current].size(); i++){
                q.push(arr[current][i]);
            }
        }
    }

    cout << cnt;
    return 0;
}