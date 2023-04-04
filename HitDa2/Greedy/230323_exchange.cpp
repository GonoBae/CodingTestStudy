#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int cost) {

    int paid = 1000;
    int change = paid - cost;
    int count = 0;
    int coin[6] = {500,100,50,10,5,1};

    for (int i = 0; i < 6 ; i++)
    {
        if (change >= coin[i])
        {
            int temp = (change / coin[i]);
            change -= temp * coin[i];
            count += temp;
        }
    }
    
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << solution(N);
    return 0;
}