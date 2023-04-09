#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int main() {
    int stock_value[1000000];
    int testcase;
    cin >> testcase;
    
    for (int i = 0; i < testcase; i++)
    {
        int day;
        cin >> day;
        for (int j = 0; j < day; ++j)
        {
            cin >> stock_value[day];
        }
        
        int max = 0;
        long long sum = 0;
        for (int j = day -1; j >= 0; --j)
        {
            if (stock_value[j] > max)
            {
                max = stock_value[j];
            }
            else
            {
                sum += (max - stock_value[j]);
            }
        }
        cout << sum << endl;
    }
    return 0;
}


int my()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int day;
        cin >> day;
        string stt;
        cin.ignore();
        getline(cin, stt);
        vector<int> temp;
        for (int j = 0; j < day; j++)
        {
            string s = stt.substr(0, stt.find(" "));
            stt.erase(0, stt.find(" ") + 1);
            temp.push_back(std::stoi(s));
        }
        int max = 0;
        long long sum = 0;
        for (int j = day -1; j >= 0; j--)
        {
            if (temp[j] > max)
            {
                max = temp[j];
            }
            else
            {
                sum += (max - temp[j]);
            }
        }
        cout << sum << endl;
    }
    return 0;
}