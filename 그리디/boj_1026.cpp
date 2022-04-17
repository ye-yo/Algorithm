#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int arr[2][50];
    for(int i = 0; i< 2; i++){
        for(int j = 0; j< N; j++){
            cin >> arr[i][j];
        }
    }

    sort(arr[0], arr[0] + N);
    sort(arr[1], arr[1] + N);
    int j = N-1;
    int sum = 0;
    for(int i = 0; i< N; i++, j--){
        sum += arr[0][i] * arr[1][j];
    }
    cout << sum;
    return 0;
}