class Solution {
public:
long long sz=(1LL<<31);
long long f(long long n,map<long long,long long>&dp){
    if(n>sz)return INT_MAX;
    if(dp.find(n)!=dp.end())return dp[n];
    long long ans=INT_MAX;
 if(n%2!=0)   {
    if(n+1<=sz){
        long long x=f(n+1,dp);
        if(x!=INT_MAX)ans=min(ans,1LL+x);
        }
         if(n-1>0){
            long long x=f(n-1,dp);
        if(x!=INT_MAX)ans=min(ans,1LL+x);
        }
        }
        else { long long x=f(n/2,dp);
            if(x!=INT_MAX)ans=min(ans,1LL+x);}
        return dp[n]=ans;
}
    int integerReplacement(int n) {
        
     map<long long,long long>dp;
        dp[0]=dp[1]=0;
        return f(n,dp);
    }
};