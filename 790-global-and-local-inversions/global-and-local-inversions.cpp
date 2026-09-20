class Solution {
public:
    bool isIdealPermutation(vector<int>&v) {
      int miv=INT_MAX;
      int n=v.size();
      for(int i=n-3;i>=0;i--){
        miv=min(miv,v[i+2]);
        if(v[i]>miv)return 0;
        
      }  
      return 1;
    }
};