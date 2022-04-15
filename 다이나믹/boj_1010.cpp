#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N,M;
        cin >> N >> M;
        long long result = 1;
        int r= 1;
        for(int i = M; i > M - N; i--){ // mCn;
            result *= i;
            result /= r++;
        }
        cout << result << "\n";
    }
    return 0;
}