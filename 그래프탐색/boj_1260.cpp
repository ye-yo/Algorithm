#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,v;
int arr[1001][1001] = {0,};
int visited[1001] = {0,};
queue<int> q;

int dfs(int i){
    visited[i] = 1;
    cout << i << " ";
    for(int j = 1; j <= n; j++){
        if(arr[i][j] == 0 || visited[j]) continue;
        dfs(j);
    }
    return 0;
}

int bfs(int start){
    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int i = q.front();
        q.pop();
        cout << i << " ";
        for(int j = 1; j<= n; j++){
            if(arr[i][j] == 0 || visited[j]) continue;
            visited[j] = 1;
            q.push(j);
        }
    }
    return 0;
}

int main(){
    cin >> n >> m >> v;
    int  x, y;
    for(int i = 0; i< m; i++){
        cin >> x >> y;
        arr[x][y] = 1;        
        arr[y][x] = 1;        
    }
    
    dfs(v);
    cout << "\n";
    for(int i = 1; i <= n;i++){
        visited[i] = 0;
    }
    bfs(v);
    return 0;
}