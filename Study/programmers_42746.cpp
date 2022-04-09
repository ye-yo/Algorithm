#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    string str_a = to_string(a);
    string str_b = to_string(b);
    return str_a + str_b > str_b + str_a; //핵심. 단순히 str_a > str_b 를 할 경우 3 30으로 정렬 안됨.
}

string solution(vector<int> numbers)
{
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);

    for (int i = 0; i < numbers.size(); i++)
    {
        answer += to_string(numbers[i]);
    }
    if (answer.at(0) == '0') // 한글자니까 "0" 대신 '0' (문자열 리터럴 대신 문자 리터럴 사용)
        return "0";
    return answer;
}

int main(void)
{
    vector<int> arr = {0, 0, 0, 0, 0};
    solution(arr);
    return 0;
}