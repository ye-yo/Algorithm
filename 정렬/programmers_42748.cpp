#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int n= 0; n < commands.size(); n++){
        int i = commands[n][0] - 1;
        int j = commands[n][1] - 1;
        int k = commands[n][2] - 1;
        int location= 0;
        vector<int> temp;
        for(int l= 0; l<array.size(); l++){
            if(l >= i && l <= j){
                temp.push_back(array[l]);
            }
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);
    }
    return answer;
}