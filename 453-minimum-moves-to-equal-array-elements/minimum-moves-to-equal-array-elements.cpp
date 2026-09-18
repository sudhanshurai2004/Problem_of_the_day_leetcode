class Solution {
public:
    int minMoves(vector<int>&v) {
        int n=v.size();
        sort(v.begin(),v.end());
        int tsum=accumulate(v.begin(),v.end(),0);
       int ans=tsum-(v[0]*n);
        return ans;
    }
};