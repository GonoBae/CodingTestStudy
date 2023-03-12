#include <iostream>
#include <string>

using namespace std;

int main()
{
    int res = 0;
    int n;
    cin >> n;

    while(n > 0)
    {
        // 5로 나누어 떨어진다.
        if (n % 5 == 0)
        {
            n -= 5;
            ++res;
        }
        // 3으로 나누어 떨어진다.
        else if (n % 3 == 0)
        {
            n -= 3;
            ++res;
        }
        // 5이상 일때
        else if (n > 5)
        {
            res -= 5;
        }
        // 위 세 조건에 만족하지 못할때
        else
        {
            res = -1;
            break;
        }
    }
    cout << res;
    
    return 0;
}