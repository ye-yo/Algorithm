#include <iostream>
using namespace std;

int main(void){
    int N,K;
    cin >> N >> K;
    int arr[100];
    int dp[10001] = {10001,};
    for(int i = 0; i< N; i++){
        cin >> arr[i];
    }

    for(int i =0; i< N;i++){
        for(int j = arr[i] + 1; j <=K; j++){
            dp[j] += min(dp[j], dp[j - arr[i]] + 1); 
        }
    }
    cout << dp[K];
    return 0;
}