class Solution {
public:
void f(int n,int k,vector<int>&v,vector<vector<int>>&ans){
    if(k==0){
        ans.push_back(v);
        return;
    }
    if(n==0){
        return;
    }
    f(n-1,k,v,ans);
    v.push_back(n);
    f(n-1,k-1,v,ans);
    v.pop_back();
    return;

}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        f(n,k,v,ans);
        return ans;

    }
};