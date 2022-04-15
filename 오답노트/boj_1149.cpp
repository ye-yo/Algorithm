#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][3];
int main(){ 
    int n;
    int cost[3];
    arr[0][0] = 0;
    arr[0][1] = 0;
    arr[0][2] = 0;
    cin >> n;
    for(int i = 1; i< n; i++){
        cin >> cost[0] >> cost[1] >> cost[2]; 
        arr[i][0] = min(arr[i-1][1],arr[i-1][2]) + cost[0]; //빨강색으로 칠할 경우 최소비용 = min(이전집초록,이전집파랑) + 비용
        arr[i][1] = min(arr[i-1][0],arr[i-1][2]) + cost[1];
        arr[i][2] = min(arr[i-1][1],arr[i-1][0]) + cost[2];
    }
    cout << min(arr[n][2],min(arr[n][0],arr[n][1]));
    return 0;
}