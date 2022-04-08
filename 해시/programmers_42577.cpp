#include <string>
#include <vector>
#include <unordered_map> 
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> map;
    for(string phone : phone_book){
        while(phone.length() > 0){
            phone.pop_back();
            map[phone]++;
        }
    }
    for(string phone : phone_book){
        if(map[phone]){
            answer = false;
            break;
        }
    }
    return answer;
}