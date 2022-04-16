#include <iostream>
using namespace std;

int main(void){
    int N,K;
    cin >> N >> K;
    int arr[101];
    int dp[10001] = {0,};
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }

    dp[0] = 1;
    for(int i =0; i < N; i++){
        for(int j = arr[i]; j <= K; j++){
            dp[j] += dp[j-arr[i]];
        }
    }
    
    cout << dp[K];
    return 0;
}