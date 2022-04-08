#include <string>
#include <vector>
#include <unordered_map> // 해시맵 사용하기위해
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> table;
    for (string name : participant){ // 이렇게 작성하면 vector 순회 가능
        table[name]++; 
    }
    for (string name : completion){
        table[name]--;
    }
    for(auto pair : table){ // 해시테이블 순회
        if(pair.second > 0){
            answer = pair.first;
            break;
        }
    }
    return answer;
}