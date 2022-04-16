#include <iostream>
#include <vector>
using namespace std;

long getWays(int n, vector<long> c) {
    long arr[251] = {0,};
    arr[0] = 1;
    for(int i=0; i<c.size(); i++){ // 2,5,4,8
        for(int j= c[i]; j<=n; j++){ //2~n까지 
            arr[j] += arr[j-c[i]];//j를 만들 수 있는 경우의 수 = j-c[i]를 만들 수 있는 경우의 수의 합       
        }
    }     
    return arr[n];
}

int main(void){
    int N,M;
    cin >> N;
    vector<long> arr;
    for(int i = 0; i< M; i++){
        cin >> arr[i];
    }

    cout << getWays(N, arr);
    return 0;
}