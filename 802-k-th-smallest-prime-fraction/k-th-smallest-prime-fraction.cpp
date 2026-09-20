class Solution {
public:
static bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    return a.first*b.second<=a.second*b.first;
}
    vector<int> kthSmallestPrimeFraction(vector<int>&v, int k) {
        int n=v.size();vector<int>ans;
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                a.push_back({v[i],v[j]});
            }
        }
        sort(a.begin(),a.end(),cmp);
        ans.push_back(a[k-1].first);
        ans.push_back(a[k-1].second);
        return ans;
    }
};