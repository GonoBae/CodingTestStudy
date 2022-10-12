#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    // �ּ� ī���� ũ��� 3x3
    int min = 3;
    int sum = brown + yellow;

    // sum�� ī���� ũ�Ⱑ ���� �� ã�� 
    for (int row = min; row <= sum / min; row++)
    {
        for (int column = min; column <= row; column++)
        {
            if (sum == row * column && yellow == (row - 2) * (column - 2))
            {
                answer.push_back(row);
                answer.push_back(column);

                return answer;
            }
        }
    }

    return answer;
}
int main()
{
    vector<int> answer;
    int brown = 24;
    int yellow = 24;

    answer = solution(brown, yellow);
    for (auto i: answer)
    {
        cout << i << ' ';
    }

    return 0;
}