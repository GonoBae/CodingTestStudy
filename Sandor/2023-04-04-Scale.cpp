#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }

    // 오름차순 정렬
    sort(weights.begin(), weights.end());

    int total = weights[0];
    if (total != 1) { cout << 1; return 0; }

    for (int i = 1; i < weights.size(); ++i)
    {
        if (total >= weights[i] || total+1 == weights[i]) { total += weights[i]; }
        else { cout << total+1; return 0; }
    }

    cout << total + 1;
    
    return 0;
}