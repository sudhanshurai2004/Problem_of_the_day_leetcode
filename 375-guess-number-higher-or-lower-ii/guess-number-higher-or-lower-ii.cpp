class Solution {
public:

int f(int lo,int hi,vector<vector<int>>&dp){
    if(hi<=lo)return 0;
    if(lo+1==hi)return lo;
    if(dp[lo][hi]!=-1)return dp[lo][hi];
    int ans=INT_MAX;
    for(int i=lo;i<=hi;i++){
            ans=min(ans,i+max(f(lo,i-1,dp),f(i+1,hi,dp)));
        }
        return dp[lo][hi]=ans;
}
    int getMoneyAmount(int n) {
        int ans=n*(n-1)/2;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=1;i<=n;i++){
            ans=min(ans,i+max(f(1,i-1,dp),f(i+1,n,dp)));
        }
        return ans;
    }
};