#include <iostream>
using namespace std;

int n, m;
int arr[101][101] = {0,};
int visited[101] = {0,};
int cnt = 0;

int dfs(int i){
    visited[i] = 1;
    for(int j = 1; j <= n; j++){
        if(arr[i][j] == 0 || visited[j]) continue;
        cnt++;
        dfs(j);
    }
    return 0;
}

int main(){
    cin >> n;
    cin >> m;
    int  x, y;
    for(int i = 0; i< m; i++){
        cin >> x >> y;
        arr[x][y] = 1;        
        arr[y][x] = 1;        
    }
    
    dfs(1);
    cout << cnt;
    return 0;
}