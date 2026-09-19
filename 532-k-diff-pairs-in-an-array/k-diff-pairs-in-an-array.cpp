class Solution {
public:
    int findPairs(vector<int>&v, int k) {
        int n=v.size();
        map<int,int>mp;
        set<pair<int,int>>st;
        int ans=0;
        for(int i=0;i<n;i++){
            int v1=v[i]-k;
            int v2=v[i]+k;
            if(mp.find(v1)!=mp.end()){
               if(st.find({min(v1,v[i]),max(v1,v[i])})==st.end()){
                st.insert({min(v1,v[i]),max(v1,v[i])});
                 ans++;
               }
               
            }
             if(v1!=v2&&mp.find(v2)!=mp.end()){
                if(st.find({min(v2,v[i]),max(v2,v[i])})==st.end()){
                st.insert({min(v2,v[i]),max(v2,v[i])});
                 ans++;
               }
            }
            mp[v[i]]++;
        }
        return ans;
    }
};