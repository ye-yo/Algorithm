#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compare(pair<int,int> a, pair<int,int> b){
    return a.second - a.first > b.second - b.first;
}
int main(void){
    int N;
    vector<pair<int,int>> meets;
    cin >> N;

    for(int i = 0; i< N; i++){
        int a, b;
        cin >> a >> b;
        meets.push_back(pair<int,int>(a,b));
    }
    sort(meets.begin(), meets.end());
    int cnt = 0;
    int last = 0;
    for(int i = 0; i< N; i++){
        if(meets[i].second < last){
            last = meets[i].second;
        }
        else{
            if(meets[i].first < last) continue;
            last = meets[i].second;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}