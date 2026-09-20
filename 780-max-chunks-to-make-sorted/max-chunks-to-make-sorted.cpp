class Solution {
public:
    int maxChunksToSorted(vector<int>&v) {
        int n=v.size();
        int ans=1;
        set<pair<int,int>>st;
        for(int i=0;i<n;i++)st.insert({v[i],i});
        int mx=INT_MIN;
        for(int i=0;i<n-1;i++){
            mx=max(mx,v[i]);
            st.erase({v[i],i});
            int val=st.begin()->first;
            if(val>=mx)ans++;
        }
        return ans;
    }
};