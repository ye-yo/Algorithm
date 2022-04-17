#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int getMinimumCost(int k, vector<int> c) {

    sort(c.rbegin(), c.rend());
    int sum = 0;
    int length = c.size() - k;
    length = floor(length / k);
    for(int i = 0; i< c.size(); i++){
        if(i < k){
            sum += c[i];
        }
        else{
            sum += c[i] * (floor(i / k) + 1);
        }
    }
    return sum;
}

int main(void){
    int N, K,num;
    vector<int> arr;
    cin >> N >> K;
    for(int i = 0; i< N; i++){
        cin >> num;
        arr.push_back(num);
    }
    cout << getMinimumCost(K, arr);
    return 0;
}