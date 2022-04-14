#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> queue;
    int day = 1;
    int completedCount = 0;
    while(progresses.size() > 0){ // 반복문 여러 번 돌 필요 없이 
        if(progresses[0] + speeds[0] * day >= 100){ // 주어진 day 안에 맨 앞의 기능이 처리되는지 여부 확인
            progresses.erase(progresses.begin()); // 처리됐으면 제거
            speeds.erase(speeds.begin());
            completedCount++; //제거
        }
        else { // 주어진 day안에 맨 앞의 기능이 처리되지 못한 경우
            if(completedCount > 0){ // 현재 day에 처리된 기능 있으면 answer에 저장하고 초기화
                answer.push_back(completedCount);
                completedCount = 0;
            }
            day++; //day 증가
        }
    }
    if(completedCount > 0)
        answer.push_back(completedCount);
    return answer;
}

int main (void){
    vector<int> a = {95, 90, 99, 99, 80, 99};
    vector<int> b = {1, 1, 1, 1, 1, 1};
    // vector<int> a = {93, 30, 55};
    // vector<int> b = {1, 30, 5};
    solution(a,b);
    return 0;
}