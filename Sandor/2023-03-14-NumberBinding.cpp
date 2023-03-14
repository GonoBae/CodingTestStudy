#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> plus;
    vector<int> minus;
    bool hasZero = false;
    int oneCount = 0;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;

        // 1 이상
        if (temp > 1)
        {
            plus.push_back(temp);
        }
        // 음수
        else if (temp < 0)
        {
            minus.push_back(abs(temp));
        }
        // 0 또는 1
        else
        {
            if (temp == 1) { ++oneCount; }
            else { hasZero = true; }
        }
    }

    // 내림차순 정렬
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end(), greater<int>());

    int answer = 0;

    // plus: 짝수이면 곱 홀수인 마지막은 더하기
    for (int i = 0; i < plus.size(); ++i)
    {
        if (1 + i < plus.size())
        {
            answer += plus[i] * plus[i + 1];
            ++i;
        }
        else
        {
            answer += plus[i];
        }
    }

    // minus: 곱하고 '-' 붙여서 합하기 마지막이 홀수이면 0이 있는지 찾기
    for (int i = 0; i < minus.size(); ++i)
    {
        if (1 + i < minus.size())
        {
            answer += minus[i] * minus[i + 1];
            ++i;
        }
        else
        {
            // 0이 있다면 0과 곱해진다.
            if (hasZero) { break; }
            // 없으면 빼기
            else { answer -= minus[i]; }
        }
    }

    // 1의 수 만큼 더하기
    cout << answer + oneCount;

    return 0;
}


// 5 4 3 2 / 1 1 / 0 0 /-1 -1 -2 -2 -3

// 5 4
// 3 2
// 1 
// 1
// -3 -2
// -2 0
// 0
