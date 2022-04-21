#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void){
    int K;
    stack<int> arr;
    cin >> K;
    int x;
    int sum = 0;
    for(int i = 0; i< K; i++){
        cin >> x;
        if(x == 0){
            int last = arr.top();
            sum -= last;
            arr.pop();
        }
        else{
            arr.push(x);
            sum += x;
        }
    }

    cout << sum;
    return 0;
}