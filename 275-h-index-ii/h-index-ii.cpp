class Solution {
public:
    int hIndex(vector<int>&v) {
        int ans=0;
        int n=v.size();
  
        for(int i=0;i<n;i++){
            int nop=i+1;
            int miv=v[n-1-i];
            if(nop<=miv)ans=max(ans,i+1);
        }
        return ans;
    }
};