#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string,int> map;
    vector<string> categories;
    for(int i = 0; i< clothes.size(); i++){
        string item = clothes[i][1];
        if(!map[item]){
            categories.push_back(item);
        }
        map[item]++;
    }

    for(string category : categories){
        answer *= map[category] + 1; // 1을 더하는 것은 해당 카테고리 의상을 입지 않는 경우를 고려하기 위해 
    }
    answer-= 1; // 해당 카테고리 의상을 입지 않는 경우를 고려하여 조합을 계산했으니 의상을 모두 미착용한 경우를 제거

    return answer;
}