#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // 오름차순 정렬
    sort(nums.begin(), nums.end());

    // 10 20 30 40
    // /10/
    // /10 + 20/    
    // /10 + 20/ + 30 
    // /10 + 20 + 30/ + 40
    // -> (10 + 20) + (30 + 30) + (60 + 40)

    int answer = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            answer += nums[j];
        }
    }
    answer -= nums[0];

    cout << answer;

    return 0;
}