class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>&v) {
        int n=v.size();
        long long ans=0LL;
        for(int i=0;i<n;i++){
            map<long long,long long >mp;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                long long x=abs(v[j][0]-v[i][0]);
                long long y=abs(v[j][1]-v[i][1]);
                
                mp[x*x+y*y]++;
            }
            for(auto it:mp)ans+=((it.second)*(it.second-1));
        }
        return ans;
    }
};