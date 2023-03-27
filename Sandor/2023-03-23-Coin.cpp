#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int answer = 0;

    cin >> n;
    int change = 1000 - n;

    while (change)
    {
        if (change >= 500) { change -= 500; }
        else if (change >= 100) { change -= 100; }
        else if (change >= 50) { change -= 50; }
        else if (change >= 10) { change -= 10; }
        else if (change >= 5) { change -= 5; }
        else { change -= 1; }

        ++answer;
    }
    
    cout << answer;
    return 0;
}
