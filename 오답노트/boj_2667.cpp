#include <iostream>
#include <queue>
using namespace std;

int n;
string graph[25];
int visited[25][25] = {0,};
queue <pair<int,int>> q;
vector <int> group;

int dx[4] = {-1,0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;
int bfs(int x, int y){ //시작 점을 시작으로 값이 1인 노드 카운팅 
    q.push({x,y});
    cnt++;
    visited[x][y] = 1;
    while(!q.empty()){ // queue가 비었다는 건 더 이상 연결되는 단지가 없다는 것. 종료
        pair<int,int> current = q.front();
        int cx = current.first;
        int cy = current.second;
        q.pop();
        
        for(int i = 0; i< 4; i++){
            int x = cx + dx[i];
            int y = cy + dy[i];
            if(x < 0 || y < 0 || x >= n || y >=n) continue;
            if(visited[x][y] && graph[x][y] == 0) continue;
            q.push({x,y});
            visited[x][y] = 1;
            cnt++;
        }
    }
}

int main(){
    cin >> n;

    for(int i = 0; i< n; i++){
        cin >> graph[i];
    }

    for(int i = 0; i< n; i++){
        for(int j = 0; j<n; j++){ 
            if(graph[i][j] == 1 && visited[i][j] != 0)
                bfs(i,j);
        }
    }

    return 0;
}