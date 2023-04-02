#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

bool myComp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}

int main()
{
    int n;
    cin >> n;

    map<char, int> alphabet;
    
    int num = 9;
    // 입력 단어 저장
    vector<string> elements(n);
    for (int i = 0; i < n; ++i)
    {
        string temp;
        cin >> temp;
        elements[i] = temp;

        // 각 문자들 저장및 자릿수 누적
        for (int j = 0; j < temp.size(); ++j)
        {
            auto it = alphabet.find(temp[j]);
            if (it == alphabet.end())
            {
                alphabet.insert({temp[j], 0});
                int pow = 1;
                for (int k = 0; k < temp.size() - j - 1; ++k)
                {
                    pow *= 10;
                }
                alphabet[temp[j]] += pow;
            }
            else
            {
                int pow = 1;
                for (int k = 0; k < temp.size() - j - 1; ++k)
                {
                    pow *= 10;
                }
                it->second += pow;
            }
        }
    }
    
    // 내림차순
    vector<pair<char, int>> tempAlphabet (alphabet.begin(), alphabet.end());
    sort(tempAlphabet.begin(), tempAlphabet.end(), myComp);

    // 순위에 따른 점수 매기기
    for (int i = 0; i < tempAlphabet.size(); ++i)
    {
        alphabet[tempAlphabet[i].first] = num;
        --num;
    }

    // 문자 변환
    for (int i = 0; i < elements.size(); ++i)
    {
        for (int j = 0; j < elements[i].size(); ++j)
        {
            elements[i][j] = alphabet[elements[i][j]] + '0';
        }
    }


    // 변환된 문자들에 대한 합산
    int answer = 0;
    for (int i = 0; i < elements.size(); ++i)
    {
        answer += stoi(elements[i]);
    }

    std::cout << answer;

    return 0;
}