#include <iostream>
#include <vector>
using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> numbers(100,0);
    for(int i = 0; i < arr.size(); i++){
        numbers[arr[i]]++;
    }
    return numbers;
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