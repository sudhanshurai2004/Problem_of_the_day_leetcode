class Solution {
public:
vector<int>ans;
bool fg=0;
void f(int ln,int n,vector<int>&st,vector<bool>&vis){
    if(fg)return;
    if(st.size()==(1<<n)){
     for(auto it:st)ans.push_back(it);
        fg=1;
        return;
    }
    for(int i=0;i<n;i++){
        int pval=((1<<i)^ln);
        if(pval>=(1<<n)||vis[pval])continue;
        st.push_back(pval);
        vis[pval]=1;
        f(pval,n,st,vis);
        vis[pval]=0;
        st.pop_back();
        
    }
    return;
}
    vector<int> grayCode(int n) {
        vector<int>st;
        st.push_back(0);
        ans.clear();
        vector<bool>vis(1<<n,0);
        vis[0]=1;
        f(0,n,st,vis);
        return ans;
    }
};