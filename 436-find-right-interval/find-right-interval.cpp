class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>&v) {
        int n=v.size();
        set<tuple<int,int,int>>st;
        vector<int>ans(n);
            for(int i=n-1;i>=0;i--){
            
         st.insert({v[i][0],v[i][1],i});
        }
        for(int i=n-1;i>=0;i--){
            auto it=st.lower_bound({v[i][1],INT_MIN,INT_MIN});
            if(it==st.end()){
ans[i]=-1;
            }
         else   ans[i]=get<2>(*it);
        
        }
        return ans;
    }
};