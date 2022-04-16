#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int arr[1000000];
    for(int i = 0; i< N; i++){
        if(i < 2) arr[i] = i+1;
        else arr[i] = (arr[i-1] + arr[i-2])% 15746;
    }
    cout << arr[N-1] % 15746;
    return 0;
}