// 1칸가고
// 나머지 순간이동
// 5 이면 0 시작 -> 1로 이동 -> 2 로 순간이동 -> 4로 순간이동 -> 5로 이동 (2)
// 6 이면 0 시작 -> 1로 이동 -> 2 로 순간이동 -> 3으로 이동 -> 6으로 순간이동 (2)

#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while(n > 0) {
        if(n % 2 != 0) {
            n -= 1;
            ++ans;
        }
        n /= 2;
    }

    return ans;
}

int main() {
    int N = 5000;
    int result = solution(N);
    cout << result;
    return 0;
}