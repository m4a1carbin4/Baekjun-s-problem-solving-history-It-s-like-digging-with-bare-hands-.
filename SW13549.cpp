#include<iostream>
typedef long long int ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;

ll arr[100001];
ll dp[100001][2];
int tc,n;

ll gcd(ll a,ll b){

    if(a<b){
        std::swap(a,b);
    }

    ll g;

    while(b>0){
        g = b;
        b = a % b;
        a = g;
    }

    return a;

}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> tc;

    for(int i=1;i<=tc;i++){
        std::cin >> n;

        for(int j=1;j<=n;j++){
            std::cin >> arr[j];
        }
        dp[1][0] = arr[1];
        dp[n][1] = arr[n];

        for(int j=2;j<=n;j++){
            dp[j][0] = gcd(dp[j-1][0],arr[j]);
        }

        for(int j=n-1;j>=1;j--){
            dp[j][1] = gcd(dp[j+1][1],arr[j]);
        }

        ll ans = std::max(dp[2][1],dp[n-1][0]);

        for(int j=2;j<n;j++){
            ans = std::max(ans,gcd(dp[j-1][0],dp[j+1][1]));
        }
        
        std::cout << "#" << i << " " << ans <<std::endl;

    }

    return 0;

}