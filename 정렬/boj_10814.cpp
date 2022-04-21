#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int compare(pair<int,string> a,pair<int,string> b ){
//     return a.first == b.first ? false : a.first < b.first;
// }

int main(void){
    int N;
    vector<pair<int,string>> arr;
    cin >> N;
    int age;
    string name;
    for(int i = 0; i< N; i++){
        cin >> age >> name;
        arr.push_back({age,name});
    }

    stable_sort(arr.begin(), arr.end());

    for(int i = 0; i< arr.size(); i++){
        cout << arr[i].first <<" " << arr[i].second << "\n";
    }
    return 0;
}