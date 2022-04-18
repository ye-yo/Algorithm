#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());
    vector<int> result;
    int minValue = 20000000;
    for(int i = 1; i< arr.size(); i++){
        minValue = min(minValue, abs(arr[i] - arr[i-1]));
    }
    for(int i = 1; i< arr.size(); i++){
        if(minValue == abs(arr[i] - arr[i-1])){
            result.push_back(arr[i-1]);
            result.push_back(arr[i]);
        }
    }
    return result;
}