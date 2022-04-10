#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int score[3] = {0, };
    int rule2[4] = {1, 3, 4, 5};
    int rule3[10] = {3, 1, 2, 4, 5};
    for (int i = 0; i < answers.size(); i++)
    {
        int rule1 = (i % 5) + 1;
        int isOdd = (i + 1) % 2;
        if (answers[i] == rule1)
            score[0]++;
        if (isOdd && answers[i] == 2)
            score[1]++;
        int value = floor(i / 2); 
        if (!isOdd && (rule2[value % 4] == answers[i]))
            score[1]++;
        if (rule3[value % 5] == answers[i])
            score[2]++;
    }
    answer.push_back(1);
    int max = score[0];
    
    for (int i = 1; i <= 2; i++)
    {
        if (max < score[i] && !answer.empty()){
            answer.clear();
            max = score[i];
        }
        if (max <= score[i])
            answer.push_back(i+1);
    }
    return answer;
}