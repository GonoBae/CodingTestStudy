#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �ִ� �����
int gcd(int a, int b)
{
    if (b == 0) { return a; }

    return gcd(b, a % b);
}

// �ּ� �����
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2)
{
    vector<int> answer;

    // denom�� ���� �и� ����� -> �ּ� �����
    int denomRes = lcm(denom1, denom2);   // �� �и��� �ּ� �����
    int numerRes = numer1 * denomRes / denom1 + numer2 * denomRes / denom2;

    // ��� �м� : ���� �ִ� ������� ������ (�ִ� ������� 1���� Ŀ�� ��)
    int gcdRes = gcd(numerRes, denomRes);
    if (gcdRes > 1)
    {
        numerRes /= gcdRes;
        denomRes /= gcdRes;
    }

    answer.push_back(numerRes);
    answer.push_back(denomRes);

    return answer;
}

int main()
{
    int numer1 = 1;
    int denom1 = 2;
    int numer2 = 3;
    int denom2 = 4;
    vector<int> result;

    result = solution(numer1, denom1, numer2, denom2);
    
    cout << result[0] << ' / ' << result[1];

    return 0;
}