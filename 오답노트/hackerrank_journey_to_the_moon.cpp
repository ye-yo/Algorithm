#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
void dfs(int n, int x, vector<int> arr[], bool visited[]){
    cnt++;
    visited[x] = true;
    for(int i = 0; i< arr[x].size(); i++){
        int next = arr[x][i];
        if(!next || visited[next]) continue;
        dfs(n,next, arr, visited);
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> arr[n + 1];
    vector<int> groups;
    bool* visited = new bool[n + 1];
    for(int i = 0; i< n; i++){
        visited[i] = false;
    }
    for(int i = 0; i< astronaut.size(); i++){
        int x = astronaut[i][0];
        int y = astronaut[i][1];
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    for(int i = 0; i< n; i++){
        cnt = 0;
        if(visited[i])continue;
        if(arr[i].empty()){  // 혼자인 비행사도 하나의 그룹으로
            groups.push_back(1);
            continue;
        }
        dfs(n, i, arr, visited);
        groups.push_back(cnt);
    }
    int result = 0;
    int sum = 0;
    for(int i = 0; i< groups.size(); i++){// 경우의 수 구하기
        if(i == 0){ 
            sum = groups[i];
            continue;
        }
        result += sum * groups[i];
        sum += groups[i];
    }
    return result;
}

int main(){
    int n,p;
    cin >> n >> p;
    vector<vector<int>> astronaut;
    for(int i = 0; i< p; i++){
        int x,y;
        cin >> x>>y;
        vector<int> t;
        t.push_back(x);
        t.push_back(y);
        astronaut.push_back(t);
    }

    cout << journeyToMoon(n, astronaut);
    return 0;
}