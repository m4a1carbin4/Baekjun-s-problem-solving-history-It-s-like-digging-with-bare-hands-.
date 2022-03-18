#include<iostream>

int main(){

    int n;
    std::cin>>n;

    long long dp[100][10];

    dp[0][0] = 0;
    for(int i=1;i<10;i++){
        dp[0][i] = 1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<10;j++){
            if(j>=1 && j<=8){
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1]) % 1000000000;
            }else if(j == 0){
                dp[i][j] = dp[i-1][j+1];
            }else if(j == 9){
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    long long ans = 0;

    for(int i=0;i<10;i++){
        ans += dp[n-1][i];
    }

    std::cout << ans % 1000000000 <<std::endl; 
}