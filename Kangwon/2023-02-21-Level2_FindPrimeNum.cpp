#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>


std::set<int> primeNumberSieve(std::string num);
std::vector<int> nums(std::string numbers);

int solution(std::string numbers) {
    int answer = 0;
    std::set<int> s = primeNumberSieve(numbers);
    std::vector<int> n = nums(numbers);

    for (auto i : n) {
        auto iter = s.find(i);
        if (iter != s.end()) {
            s.erase(s.find(i));
            answer++;
        }
    }
    return answer;
}

int main() {
    int cnt = 0;
    std::set<int> s = primeNumberSieve("011");
    std::vector<int> n = nums("011");

    for (auto i : n) {
        auto iter = s.find(i);
        if (iter != s.end()) {
            s.erase(s.find(i));
            cnt++;
        }
    }  

    std::cout << cnt;
    return 0;
}

//에라토스테네스의 체를 이용해서 set에 데이터를 담아줌
//set에 넣는 이유는 탐색이 빠르기 때문
//set, map 은 모두 R-B 트리로 구성된다.
std::set<int> primeNumberSieve(std::string num)
{
    int tmp = 1;
    for(int i =0;i<num.length();++i){
        tmp *= 10;
    }

    std::vector<bool> arr(tmp + 1);
    arr[1] = true;
    for (int i = 2; i <= sqrt(tmp); i++) {
        if (arr[i]) continue;
        for (int j = i + i; j <= tmp; j += i)
            arr[j] = true;
    }
    std::set<int> prime;
    // 소수 출력
    for (int i = 2; i <= tmp; i++) {
        if (!arr[i]) {
            //std::cout << i << std::endl;
            prime.insert(i);
        }
    }
    return prime;
}

//순열과 조합을 이용해서 얻을 수 있는 경우의 수를 전부 가져옴
std::vector<int> nums(std::string numbers)
{
    std::vector<int> r;
    int len = numbers.size();
    for (int i = 1; i <= len; i++) {
        std::vector<bool> v(len - i, false);
        v.insert(v.end(), i, true);
        //{f,f,f,f,t}
        //->{f,f,f,t,t}
        //이런식으로 반복함
        do {
            std::vector<char> t;
            for (int k = 0; k < len; k++) {
                if (v[k]) t.push_back(numbers[k]);
            }

            std::sort(t.begin(), t.end());
            do
            {
                std::string str = "";
                for (auto it : t) {
                    str += it;
                }
                r.push_back(stoi(str));
            } while (next_permutation(t.begin(),t.end()));
        } while (next_permutation(v.begin(), v.end()));
    }
    return r;
}

