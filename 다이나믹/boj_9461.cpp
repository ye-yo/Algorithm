#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int i =0; i< T; i++){
        int N;
        cin >> N;
        long arr[100] = {0,};
        arr[0] = 1;
        for(int j = 0; j < N; j++){
            if(j <3) arr[j] = 1;
            else{
                arr[j] = arr[j-2] + arr[j-3];
            }
        }
        cout << arr[N-1] << "\n";
    }
}