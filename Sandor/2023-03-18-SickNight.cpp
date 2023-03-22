#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // n이 1 일때는 제자리
    if (n == 1) { cout << 1; }
    // n이 2일때 2번,3번 조건만 사용가능
    // 때문에 다음칸에 말을 놓을때마다 m은 3칸 부터 2칸씩 필요
    // 최대 2번,3번 조건을 쓸수 없기 때문에 최대 4개까지 가능
    else if (n == 2) { cout << min(4, (m + 1) / 2); }
    // n이 3이상 이면 1,2,3,4번 조건을 모두 사용 할 수 있다.
    else
    {
        // 1,4번 조건만 사용해서 최단 거리를 이동 할 수 있는 최대치
        if (m <= 6) { cout << min(4, m); }
        // 2,3번 조건을 한 번 사용해야 하기때문에 두 칸(-2)을 더 소비하게 된다.
        else { cout << m - 2; }
    }

    return 0;
}
