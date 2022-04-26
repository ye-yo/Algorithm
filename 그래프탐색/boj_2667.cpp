#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int,int>> q;
string arr[25];
int visited[25][25] = {0,};
int N;

int bfs(){
    int cnt = 0;
    while(!q.empty()){
        pair<int,int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        if(visited[x][y]) continue;
        visited[x][y] = 1;
        cnt++;
        for(int i = 0; i < 4; i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)continue;
            if(visited[nextX][nextY]) continue;
            if(arr[nextX][nextY] == '1'){
                q.push({nextX,nextY});
            }
        }
    }
    return cnt;
}

int main(void){
    cin >> N;
    for(int i = 0; i< N; i++){
        cin >> arr[i];
    }
    vector<int> result;
    for(int i =0; i < N; i++){
        for(int j =0; j < N; j++){

            if(visited[i][j] || arr[i][j] == '0') continue;
            q.push({i,j});
            int houseCount = bfs();
            if(houseCount > 0){
                result.push_back(houseCount);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(int i = 0; i< result.size(); i++){
        cout << result[i] << "\n";
    }
    return 0;
}