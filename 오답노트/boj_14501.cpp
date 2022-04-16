#include <iostream>
using namespace std;

int main(void){
    int N;
    int T[18];
    int P[18];
    int dp[18] = {0,};
    cin >> N;
    for(int i = 1; i<= N; i++){
        cin >> T[i] >> P[i];
    }

    for(int i= N; i>0; i--){
        int end = T[i] + i;
        if(T[i] + i - 1 > N) dp[i] = dp[i+1]; //만료일자가 N보다 크면 안됨
        else dp[i] = max(P[i] + dp[end],dp[i+1]);
        //예를 들어 5일차는 소요일수가 2일
        //2일 소요되면 6일차 일을 진행못함 
        //=> 5일차 일을 진행했을 경우 vs 5일차 일을 하지 않고 6일차 일을 진행했을 경우 
        //=> 5일차 일을 진행했을 경우 = 5일차 일을 진행한 금액 + 5일차 일이 종료되는 날에 일을 진행했을 경우
        // => max(dp[i+1], P[i] + dp[end]);
    }
    cout << dp[1];
    return 0;
}