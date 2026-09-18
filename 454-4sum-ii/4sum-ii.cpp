class Solution {
public:
    int fourSumCount(vector<int>&v1, vector<int>&v2, vector<int>&v3, vector<int>& v4) {
        map<int,int>mp1,mp2;
        int n=v1.size();
        for(int i=0;i<n;i++)for(int j=0;j<n;j++){
            mp1[v1[i]+v2[j]]++;
        }
         for(int i=0;i<n;i++)for(int j=0;j<n;j++){
            mp2[v3[i]+v4[j]]++;
        }
        int ans=0;
        for(auto it:mp1){
            int val=-1;
            val*=it.first;
            if(mp2.find(val)!=mp2.end()){
                ans+=it.second*mp2[val];
            }
        }
        return ans;
    }
};