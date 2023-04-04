#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int level, vector<int> scores) {
    int count = 0;
    for (int i = level-1; i > 0; i--)
    {
        if (scores[i-1] >= scores[i])
        {
            int temp = scores[i - 1] - scores[i] + 1;
            count += temp;
            scores[i - 1] -= temp;
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> a;

    for (int i = 0; i < n; i++)
    {
        int score;
        cin >> score;
        a.push_back(score);
    }

    cout << solution(n, a);
    return 0;
}