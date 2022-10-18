#include <iostream>

using namespace std;

int main()
{ 
    int n;
    int answer = 0;
    cin >> n;

    // 1. 5로 나누어 떨어지는가?
    // 2. 3으로 나누어 떨어지는가?
    // 3. 5보다 크고 위 두 조건이 만족하지 않을경우
    // 4. 위 조건들이 만족하지 않는 나머지 (만들 수 없는 수)
    while (n > 0)
    {
        if (n % 5 == 0)
        {
            n -= 5;
            answer++;
        }
        else if (n % 3 == 0)
        {
            n -= 3;
            answer++;
        }
        else if (n > 5)
        {
            n -= 5;
            answer++;
        }
        else
        {
            answer = -1;
            break;
        }
    }

    cout << answer;

    return 0;
}