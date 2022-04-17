#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int minDiff = 2000000001;
    for(int i = 1; i< arr.size(); i++){
        int diff = abs(arr[i - 1] - arr[i]);
        minDiff = min(minDiff, diff);
    }
    return minDiff;
}

int main(void){
    int N;
    vector<int> arr;
    cin >> N;
    for(int i = 0; i< N; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    cout << minimumAbsoluteDifference(arr);
    return 0;
}