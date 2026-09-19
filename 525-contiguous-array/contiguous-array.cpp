class Solution {
public:
    int findMaxLength(vector<int>&v) {
        int n=v.size();
        int ans=0;
        map<int,int>mp;
        mp[0]=-1;
        int sc=0;
        for(int i=0;i<n;i++){
            if(v[i]==0)sc--;
            else sc++;
            if(mp.find(sc)!=mp.end()){
ans=max(ans,i-mp[sc]);
            }else{
mp[sc]=i;
            }
        }
        return ans;
    }
};