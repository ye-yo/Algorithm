#include <iostream>
#include <math.h>
using namespace std;

int main(void){
    int N, K;
    int arr[1000000];
    cin >> N >> K;
    for(int i = 0; i< N; i++){
        cin >> arr[i];
    }

    int cnt = 0;
    for(int i =N-1; i>=0; i--){
        if(K == 0) break;
        if(arr[i] > K) continue;
        int a = floor(K / arr[i]);
        K -= a * arr[i];
        cnt += a;
    }
    cout << cnt;
    return 0;
}