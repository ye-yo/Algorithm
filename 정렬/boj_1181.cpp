#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compare (string a, string b){
    return a.length() == b.length() ? a < b:a.length() < b.length();
}
int main(void){
    int N;
    vector<string> arr;
    cin >> N;
    string s;
    for(int i = 0; i< N; i++){
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), compare);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] <<"\n";
    }
    return 0;
}