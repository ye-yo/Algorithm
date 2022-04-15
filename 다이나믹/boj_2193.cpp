#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    long arr[90][2];
    arr[0][0] = 0;
    arr[0][1] = 1;
    for(int i = 1; i< N; i++){
        arr[i][0] = arr[i -1][1] + arr[i-1][0];
        arr[i][1] = arr[i-1][0];
    }
    cout << arr[N-1][0] + arr[N-1][1];
    return 0;
}