class Solution {
public:
    int hIndex(vector<int>&v) {
        int ans=0;
        int n=v.size();
        sort(v.rbegin(),v.rend());
        for(int i=0;i<n;i++){
            int nop=i+1;
            int miv=v[i];
            if(nop<=miv)ans=max(ans,i+1);
        }
        return ans;
    }
};