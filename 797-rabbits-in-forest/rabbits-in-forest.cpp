class Solution {
public:
    int numRabbits(vector<int>&v) {
        int n=v.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)mp[v[i]]++;
        int ans=0;
        for(auto it:mp){
            ans+=(it.first+1)*((it.second+it.first)/(it.first+1));

        }
        return ans;
    }
};