#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    int answer = 0;

    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    
    int max = nums[n - 1]; // 기준점
    for (int i = n-2; i >= 0; --i)
    {
        if (nums[i] < max) 
        {
            max = nums[i];
            continue; 
        }
        
        // 최고점 보다 높으면 깎아내기
        answer += nums[i] - (max - 1);
        nums[i] = max - 1;
        max = nums[i];
    }

    cout << answer;
    return 0;
}