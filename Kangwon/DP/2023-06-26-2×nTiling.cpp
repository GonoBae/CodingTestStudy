#include<iostream>

int dp[1001];

int main(){
    int input;
    std::cin>>input;
    
    dp[1] =1;
    dp[2] =2;
    
    for(int i =3;i<=input;i++){
        dp[i]= (dp[i-2]+dp[i-1])%10007;
    }
    
    std::cout<<dp[input];
    return 0;
}
