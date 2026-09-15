class Solution {
public:
    int maximumGap(vector<int>&v) {
        int n=v.size();
        if(n<2)return 0;
        int mxv=*max_element(v.begin(),v.end());
        int miv=*min_element(v.begin(),v.end());
        vector<pair<int,int>>b(n+2,{INT_MAX,INT_MIN});

    int gap=((mxv-miv+n-2)/(n-1));
    if(gap==0)return 0;
    for(int i=0;i<n;i++){
        int idx=(v[i]-miv)/gap;
        if(b[idx].second<v[i])b[idx].second=v[i];
        if(b[idx].first>v[i])b[idx].first=v[i];
        
    }
    int ans=0;
    int lv=miv;
    for(int i=0;i<n+2;i++){
        if(b[i].first==INT_MAX)continue;
ans=max(ans,b[i].first-lv);
      
        lv=b[i].second;
       
        
       

    }
return ans;
    }
};