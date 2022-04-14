#include <iostream>
#include <queue>
using namespace std;

int graph[101][101] = {0,}; //또는 string graph[101];
int dist[101][101] = {0,}; // 이동 거리 저장 
int visited[101][101] = {0,};
int n, m;
int result = 0;
queue<pair<int,int>> q; //좌표 넣어줄 queue;

int main(void){
    cin >> n >> m;
    for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]); //또는 string으로 입력받고 탐색시에는 배열로 접근하면 됨 
		}
	}
    int dx[4] = {1,0,-1,0};  // 상하좌우 탐색 위한 dx,dy 이동 좌표
	int dy[4] = {0,1,0,-1};

    visited[0][0] = 1;
    q.push({0,0});
    while(!q.empty()){

        pair<int,int> current = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = current.first + dx[dir]; //queue에서 꺼낸 pair를 nx,ny에 할당
            int ny = current.second + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 초과 시 넘어감
            if(graph[nx][ny] == 0 || visited[nx][ny]) continue; // 문자열로 받았을 경우 == '0'

            dist[nx][ny] = dist[current.first][current.second] + 1; // 이동 거리 업데이트
            q.push({nx,ny}); // 다음으로 탐색할 노드 추가
            visited[nx][ny] = 1;
        }
    }
    cout << dist[n-1][m-1];
    return 0;
}