#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int main(void){
    int N;
    vector<pair<int,int>> arr;
    cin >> N;
    int x,y;
    for(int i = 0; i< N; i++){
        cin >> x >> y;
        arr.push_back({y, x});
    }

    sort(arr.begin(), arr.end(), compare);
    for(int i = 0; i< N; i++){
        cout << arr[i].second << " " << arr[i].first << "\n";
    }
    return 0;
}