#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}
vector<string> solution(vector<string> o, vector<int> c)
{
    vector<string> answer;
    sort(o.begin(), o.end());
    for (int i = 0; i < c.size(); i++)
    {
        map<string, int> comb;
        for (int j = 0; j < o.size(); j++)
        {
            if (c[i] <= o[j].size())
            {
                // 주문에서 나올 수 있는 코스의 경우의 수를 전부 계산한다.
                vector<int> v;
                for (int k = 0; k < c[i]; k++)
                    v.push_back(1);
                for (int k = 0; k < o[j].size() - c[i]; k++)
                    v.push_back(0);
                sort(v.begin(), v.end());
                do
                {
                    string str = "";
                    for (int k = 0; k < v.size(); k++)
                    {
                        if (v[k] == 1)
                            str += o[j][k];
                    }
                    sort(str.begin(), str.end());
                    comb[str] += 1;
                } while (next_permutation(v.begin(), v.end()));
                //next_permutation -> 경우의 수를 전부 계산한다.
                //{0,0,0,1,1}의 벡터를 만들어 놓고
                //->{0,0,1,0,1} 이런식으로 계속 변경함
                // 2차원 배열을 쓰는거랑 뭐가 다른거지?
                //이후 정렬을 해서 맵에 넣어준다. 이때 정렬을 하는 이유는 AC/CA 케이스가 둘로 나뉘지 않게하기 위해
                //
            }
        }
        vector<pair<string, int>> vec(comb.begin(), comb.end());
        sort(vec.begin(), vec.end(), cmp);
        int max;
        if (!vec.empty())
            max = vec[0].second;
        if (max != 1)
        {
            for (auto m : vec)
            {
                if (max == m.second)
                    answer.push_back(m.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector<string> order = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2,3,4 };
    solution(order, course);
}