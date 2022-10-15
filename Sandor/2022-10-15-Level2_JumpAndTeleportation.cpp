#include <iostream>

using namespace std;

// 2�� �ŵ����� �Ǻ�
bool isTwoPower(int n)
{
    int temp = 1;
    while (true)
    {
        temp *= 2;

        if (temp == n) { return true; }
        else if (temp > n) { return false; }
    }
}

// n�� 2�� �ŵ� �����϶� ���� ���� Ƚ���� �̵� �����ϴ�
int solution(int n)
{
    int ans = 1;

    if (!isTwoPower(n))
    {
        while (n > 1)
        {
            if (n % 2 == 1) { ans++; }   // ������ �������� ������ �����ؾ� ��
            n /= 2;
        }
    }

    return ans;
}

int main()
{
    int n = 5000;
    cout << solution(n);

    return 0;
}