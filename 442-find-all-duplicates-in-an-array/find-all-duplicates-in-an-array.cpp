class Solution {
public:
    vector<int> findDuplicates(vector<int>&v) {
        int n=v.size();
        vector<int>ans;
       int idx=0;
       while(idx<n){
        int cidx=v[idx]-1;
        if(v[cidx]!=v[idx]){
            swap(v[idx],v[cidx]);
        }
        else idx++;
       }
       for(int i=0;i<n;i++)if(v[i]!=i+1)ans.push_back(v[i]);
       
       return ans;

    }
};