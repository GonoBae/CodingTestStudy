#include <iostream>
#include <string>
#include <vector>

using namespace std;

string correctBabbling[4] = { "aya", "ye", "woo", "ma" };
int babblingSize[4] = { 3, 2, 3, 2 };

int solution(vector<string> babbling)
{
    int answer = 0;

    for (int i = 0; i < babbling.size(); ++i)
    {
        string temp = babbling[i];
        string prevStr = "";

        for (int j = 0; j < 4; ++j)
        {
            // 찾으면 해당 범위의 string 제거
            auto it = temp.find(correctBabbling[j]);

            // 공백이 되었거나 이전에 찾은 string의 첫 문자와 현재 가장 앞의 문자가 같으면 break
            // 현재 가장 앞의 문자와 찾고자 하는 옹알이의 첫 문자 비교
            if (temp == "" || prevStr[0] == temp[0]) { break; }
            else if (temp[0] != correctBabbling[j][0]) { continue; }

            // 찾으면 idx를 0으로 만들어 다시 탐색
            if (temp.find(correctBabbling[j]) != string::npos)
            {
                temp.erase(it, it + babblingSize[j]);
                prevStr = correctBabbling[j];
                j = -1;
            }
        }

        if (temp == "") { answer += 1; }
    }

    return answer;
}

int main()
{
    vector<string> babbling = { "ayaye", "ayayeaya", "yeayaye"};
    int answer = solution(babbling);
    cout << answer;

    return 0;
}