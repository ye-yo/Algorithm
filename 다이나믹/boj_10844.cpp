#include <iostream>
using namespace std;

int arr[101][10];
int main(){
    int N;
    cin >> N;
    
    arr[0][0] = 0;
    for(int i = 1; i <= 10; i++){
        arr[0][i] = 1;
    }
    
    for(int i = 1; i < N; i++){
        arr[i][0] = arr[i-1][1]; // 양 끝은 별도 계산
        arr[i][9] = arr[i-1][8]; 
        for(int j = 1; j < 9; j++){
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j+1]; //
        }
    }
    int result = 0;
    for(int i = 0; i<= N; i++){
        result = (result + arr[N-1][i]) % 1000000000; // 여기서 모듈러 연산해주기.(값이 커지는 것 미리방지)
    }
    cout << result ;
}