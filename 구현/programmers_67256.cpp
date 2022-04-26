#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lastL = 10, lastR = 12;
    for(int i = 0; i< numbers.size(); i++){
        bool isLeft = false;
        int number = numbers[i];
        if(number == 0){
            number = 11;
        }
        if(number % 3 == 2){
            int a = lastL - 1, b = lastR - 1, c = number - 1;
            int leftMove = abs(a / 3 - c / 3) + abs(a % 3 - c % 3);
            int rightMove = abs(b / 3 - c / 3) + abs(b % 3 - c % 3);
            
            if(leftMove < rightMove)
               isLeft = true;
            if(hand == "left"){
                if((lastL == 10 && lastL == lastR) || 
                   (leftMove == rightMove))
                    isLeft = true;
            }
        }
        
        if(number % 3 == 1 || isLeft){
            answer += "L";
            lastL = number;
        }
        else{
            answer += "R";
            lastR = number;
        }
    }
    return answer;
}