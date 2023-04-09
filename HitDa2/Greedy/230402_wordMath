#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <utility>
using namespace std;
int main(){
    int n;
    int alpha[26] = {};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        int pow = 1;
        for (int j = input.length() - 1; j >= 0; j--)
        {
            alpha[input[j] - 'A'] += pow;
            pow *= 10;
        }
    }

    sort(alpha, alpha + 26, greater<int>());
    int num = 9;
    int answer = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == 0)
        {
            break;
        }
        answer += (alpha[i] * num);
        num--;
    }
    cout << answer << endl;
    return 0;
}



int my() {
    int n;
    int maxLen = 0;

    vector<string> cap;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        int len = c.length();
        if (c.length() < 8)
        {
            char temp = '0';
            char t[8];
            for (int j = 0; j < 8; j++)
            {
                if (j < 8 - len)
                {
                    t[j] = temp;
                }
                else
                {
                    t[j] = c[j - (8 - len)];
                }
            }
            cap.push_back(t);
        }
    }

    pair<char, int> p[10];
    int num = 9;
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < cap.size(); j++)
        {
            string temp = cap[j];
            if (temp[i] != '0')
            {
                bool go = false;
                for (int k = 0; k < 10; k++)
                {
                    if (p[k].first == temp[i])
                    {
                        cap[j].replace(i, 1, to_string(p[k].second));
                        go = true;
                        break;
                    }
                }
                if (!go)
                {
                    p[9 - num] = make_pair(temp[i], num);
                    cap[j].replace(i, 1, to_string(num));
                    num--;
                }
            }
        }
    }
    for (int i = 0; i < cap.size(); i++)
    {
        cap[i].resize(8);
        sum += stoi(cap[i]);
    }
    cout << sum << endl;
    return 0;
}