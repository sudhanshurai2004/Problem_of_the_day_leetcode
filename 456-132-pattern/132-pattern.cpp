class Solution {
public:
    bool find132pattern(vector<int>&v) {
        vector<int>v1=v,v2=v;
        int n=v.size();
        int miv=INT_MAX;
        for(int i=0;i<n;i++){
            v1[i]=miv;
            miv=min(miv,v[i]);
        }
        set<int>st;
        st.insert(v[n-1]);
        for(int i=n-2;i>=0;i--){
            auto it=st.upper_bound(v1[i]);
            if(it!=st.end()&&*it<v[i])return 1;
            st.insert(v[i]);
        }
        return 0;
    }
};