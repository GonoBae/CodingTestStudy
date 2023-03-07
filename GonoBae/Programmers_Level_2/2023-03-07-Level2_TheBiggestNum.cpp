#include<iostream>
using namespace std;

long long gcd(int a, int b) {
    long n;
    while(b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

long long solution(int w,int h) {
    long long W = w;
    long long H = h;
    long long tmp = (w + h) - gcd(w, h);
    return (W*H) - tmp;
}