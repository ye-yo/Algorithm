#include <iostream>
using namespace std;

int prime(int target){
    bool isPrime = true;
    for(int i = 2; i*i <= target; i++){
        if(target % i == 0){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}
int main(void){
    int M,N;
    int arr[50];
    cin >> M >> N;
    for(int i = M; i<= N; i++){
        if(i == 1) continue;
        if(prime(i))
            cout << i << "\n";
    }
    return 0;
}

//에라토스테네스의 체를 이용해 구현하는 것을 추천