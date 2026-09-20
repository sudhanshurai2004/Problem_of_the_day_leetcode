class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';

            if(idx<=13)idx=26-idx;
            else{
                idx=26-idx;
            }
            cout<<idx<<endl;
            int val=(i+1)*(idx);
            cout<<val<<endl;
            ans+=val;
        }
        return ans;
    }
};