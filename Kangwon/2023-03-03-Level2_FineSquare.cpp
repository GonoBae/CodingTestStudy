#include <iostream>
#include <vector>

int gcd(int a, int b);
int line(int w, int h);

long long solution(int w, int h) {
    
    long long answer = w * h;

    int tmp = gcd(w, h);

    answer -= (line(w / tmp, h / tmp) - 1) * tmp;

    return answer;
}

int gcd(int a, int b) {
    int tmp, n;

    if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}
int line(int w, int h) {

    int cnt = 0;
    int x = 0, y = 0;
    //기울기에 따라 다른 판별식을 사용한다. 
    bool chk = w >= h;

    int f = chk ? h * 2 - w : w * 2 - h;
    int f1 = chk ? 2 * h : 2 * w;
    int f2 = chk ? 2 * (h - w) : 2 * (w - h);

    if (chk) {
        while (x != w) {
            cnt++;
            if (f < 0) {
                f += f1;
            }
            else {
                cnt++;
                f += f2;
                y += 1;
            }
            x += 1;
        }
    }
    else {
        while (y != h) {
            cnt++;
            if (f < 0) {
                f += f1;
            }
            else {
                cnt++;
                f += f2;
                x += 1;
            }
            y += 1;
        }
    }
    return cnt;
}

int main() {
    std::cout << solution(8,12);

    return 0;
}