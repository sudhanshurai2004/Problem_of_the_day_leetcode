class Solution {
public:
    int numFriendRequests(vector<int>&a) {
        int n=a.size();
        vector<int>v;
        for(int i=0;i<n;i++)v.push_back(a[i]);
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int idx=upper_bound(v.begin(),v.end(),(v[i]/2)+7)-v.begin();
            int high = upper_bound(v.begin(), v.end(), v[i]) - v.begin();
            ans+=max(0,high-idx-1);
        }
        return ans;
    }
};