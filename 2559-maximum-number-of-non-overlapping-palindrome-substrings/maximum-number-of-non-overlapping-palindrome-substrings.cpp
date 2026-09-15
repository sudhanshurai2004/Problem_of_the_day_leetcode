class Solution {
public:
int f(int idx,string &s,int k,vector<int>&dp,vector<vector<bool>>&pal){
    int n=s.size();
    if(idx>=n)return 0;
     if(dp[idx]!=-1)return dp[idx];
    int ans=f(idx+1,s,k,dp,pal);
   
    for(int i=idx+k-1;i<n;i++){
        if(pal[idx][i])ans=max(ans,1+f(i+1,s,k,dp,pal));
    }
   
    return dp[idx]=ans;
}
    int maxPalindromes(string s, int k) {
             int n=s.size();
        vector<vector<bool>>pal(n,vector<bool>(n,0));
        for(int i=0;i<n;i++)pal[i][i]=true;
        for(int len=2;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                if(s[i]==s[i+len-1]){
                    if(len==2)pal[i][i+len-1]=true;
                    else pal[i][i+len-1]=pal[i+1][i+len-2];
                }
            }
        }
        vector<int>dp(n+1,-1);
        return f(0,s,k,dp,pal);
    }
};