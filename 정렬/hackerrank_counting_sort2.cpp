#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countingSort(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

int main(void){
    int N,n;
    vector<int> arr;
    cin >> N;
    for(int i = 0; i< N; i++){
        cin >> n;
        arr.push_back(n);
    }
    countingSort(arr);
    return 0;
}