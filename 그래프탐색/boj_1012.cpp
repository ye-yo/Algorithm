#include <iostream>
#include <queue>
using namespace std;

int n, m, k, t;
int arr[50][50] = {0,};
int visited[50][50] = {0,};
queue<pair<int,int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int i, int j){
    q.push({i,j});
    while(!q.empty()){
        pair<int,int> current = q.front();
        q.pop();
        for(int d = 0; d < 4; d++){
            int x = current.first + dx[d];
            int y = current.second + dy[d];
            if(x <0 || y<0 || x >= m || y >= n) continue;
            if(arr[x][y] != t || visited[x][y] == t) continue;
            q.push({x,y});
            visited[x][y] = t;
        }
    }
    return 0;
}

int main(){
    int x, y;
    cin >> t;
    for(; t > 0; t--){ 
        int cnt = 0;
        cin >> m >> n >> k;
        for(int i = 0; i< k; i++){
            cin >> x >> y;
            arr[x][y] = t;        
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(visited[i][j] == t|| arr[i][j] != t) continue;
                cnt++;
                bfs(i, j);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}