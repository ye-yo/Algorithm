#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    int P[1000];
    cin >> N;
    for(int i = 0; i< N; i++){
        cin >> P[i];
    }
    sort(P, P + N);
    int sum = P[0];
    for(int i = 1; i< N; i++){
        P[i] = P[i] + P[i-1];
        sum += P[i];
    }

    cout << sum;
    return 0;
}