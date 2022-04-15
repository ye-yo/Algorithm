#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int bfs(int start, int n, vector<int> cities[],bool visited[]){
    queue <int> q;
    q.push(start);
    visited[start] = true;
    int road = 1;
    while(!q.empty()){
        int i = q.front();
        q.pop();
        for(int j = 0; j < cities[i].size(); j++){
            int node = cities[i][j];
            if(!node || visited[node]) continue;
            visited[node] = true;
            q.push(node);
            road++;
        }
    }
    return road - 1; //간선개수만
}
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    if(c_lib <= c_road) return (long)n * c_lib; // long 반환 타입 맞추기
    bool* visited = new bool [n+1];
    vector<int> arr[n + 1];
    long long total_cost = 0;
    int alone = 0;
    for(int i= 1; i<= n; i++){ // 배열 초기화 확실하게
        visited[i] = false;
    }
     //[[1,3],[2,4],[1,4]] 이렇게 되어있는 배열을
     // [ ,[3,4],[4]] 이런식으로 변경
    for(int i = 0; i<cities.size(); i++){
        if(cities[i].size() == 0)continue;
        int x = cities[i][0];
        int y = cities[i][1];
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    for(int i= 1; i<= n; i++){
        if(visited[i])continue;
        int roadCount = bfs(i, n, arr, visited);
        total_cost += (roadCount * c_road) + c_lib;
    }
    return total_cost;
}

int main()
{
    int c;
    cin >> c;
    for(; c >0; c-- ){
        int n, m, c_lib, c_road;
        cin >> n >> m >> c_lib>> c_road;
        int x,y;
        vector<vector<int>> cities;
        for(int i = 0; i< m; i++){
            cin >> x >> y;
            vector<int> arr;
            arr.push_back(x);
            arr.push_back(y);
            cities.push_back(arr);
        }
        long result = roadsAndLibraries(n, c_lib, c_road, cities);
        cout << "답: " <<result << "\n";
    }
    return 0;
}
