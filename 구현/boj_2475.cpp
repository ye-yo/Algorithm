#include <iostream>
using namespace std;

int main(void){
    long sum = 0,n;
    for(int i = 0; i< 5; i++){
        cin >> n;
        sum += n*n;
    }
    cout << sum % 10;
    return 0;
}