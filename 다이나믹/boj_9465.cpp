#include <iostream>
using namespace std;

int main(void){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int arr[2][100000] = {0,};
        int dp[2][100000] = {0,};
        for(int j = 0; j< 2; j++){
            for(int i = 0; i< N; i++){
                cin >> arr[j][i];
            }
        }

        for(int i=0; i< N; i++){
            if(i == 0){
                dp[0][i] = arr[0][i];
                dp[1][i] = arr[1][i];
            }
            else if(i == 1){
                dp[0][i] = max(dp[1][i-1] + arr[0][i],dp[0][i-1]);
                dp[1][i] = max(dp[0][i-1] + arr[1][i],dp[1][i-1]);
            }
            else{
                dp[0][i] = max(max(dp[0][i-2] + arr[1][i-1], dp[1][i-1]) + arr[0][i], dp[0][i-1]);
                dp[1][i] = max(max(dp[1][i-2] + arr[0][i-1], dp[0][i-1]) + arr[1][i], dp[1][i-1]);
            }
        }
        cout << max(dp[0][N-1], dp[1][N-1]) << "\n" ;
    }
    return 0;
}