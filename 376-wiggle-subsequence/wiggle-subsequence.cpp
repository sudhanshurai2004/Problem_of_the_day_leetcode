class Solution {
public:
int f(int idx,int li,bool fg,vector<int>&v,vector<vector<vector<int>>>&dp){
    int n=v.size();
    if(idx>=n)return 0;
    int ans=n-idx;
    if(dp[idx][li+1][fg]!=-1)return dp[idx][li+1][fg];
    for(int i=idx;i<n;i++){
        if(fg==1){
if(li==-1){
    ans=min(ans,i-idx+f(i+1,i,!fg,v,dp));
}else{
    if(v[i]<v[li]){
           ans=min(ans,i-idx+f(i+1,i,!fg,v,dp));
    }
}
        }else{
if(li==-1){
    ans=min(ans,i-idx+f(i+1,i,!fg,v,dp));
}else{
    if(v[i]>v[li]){
           ans=min(ans,i-idx+f(i+1,i,!fg,v,dp));
    }
}
        }
    }
    return dp[idx][li+1][fg]=ans;
}
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
int lv=INT_MIN;
vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
ans=min(ans,f(0,-1,1,nums,dp));
lv=INT_MAX;
ans=min(ans,f(0,-1,0,nums,dp));
return n-ans;
    }
};