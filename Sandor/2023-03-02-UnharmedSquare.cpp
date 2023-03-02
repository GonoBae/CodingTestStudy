#include <iostream>

using namespace std;

// 최대공약수 구하기
long long getGcd(long long w, long long h)
{
    if (h == 0) { return w; }

    return getGcd(h, w % h);
}

// 규칙적인 패턴이 반복되는 횟수 = w와 h의 최대공약수
// 패턴의 가로 = w / gcd, 패턴의 세로 = h / gcd
// 가로줄 기준 2칸을 차지하는 경우 w / gcd - 1
long long solution(int w, int h)
{
    long long longW = w;
    long long longH = h;
    long long total = longW * longH;

    long long gcd = getGcd(longW, longH);
    int patternW = longW / gcd;
    int patternH = longH / gcd;

    long long answer = total - ((patternW + patternH - 1) * gcd);

    return answer;
}

int main()
{
    int w = 8;
    int h = 12;
    int answer = solution(w, h);
    cout << answer;

    return 0;
}