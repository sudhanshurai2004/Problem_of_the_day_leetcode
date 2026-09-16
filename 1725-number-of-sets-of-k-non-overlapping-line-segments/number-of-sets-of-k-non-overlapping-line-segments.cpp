class Solution {
public:
int mod=1e9+7;
using ll=long long;
    int numberOfSets(int n, int k) {
        vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>> (k+1,vector<ll>(2,0)));
        
        dp[0][1][0]=1;
        dp[0][0][1]=1;

        for(ll i=1;i<n;i++){
            dp[i][0][1]=1;

            for(ll j=1;j<=k;j++){
                dp[i][j][1]=(dp[i-1][j][1]+dp[i-1][j][0])%mod;
                dp[i][j][0]=(dp[i][j-1][1]+dp[i-1][j][0])%mod;
            }
            
        }

        return dp[n-1][k][1];
    }
};