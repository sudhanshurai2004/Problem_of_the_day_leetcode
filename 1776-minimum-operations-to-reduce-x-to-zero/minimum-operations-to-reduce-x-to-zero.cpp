class Solution {
public:

    int minOperations(vector<int>& v, int x) {
       int n=v.size();
       int tsum=accumulate(v.begin(),v.end(),0);
       int tar=tsum-x;
       if(tar<0)return -1;
       int si=0;
       int cs=0;
       long long ans=LLONG_MIN;
     

       for(int i=0;i<n;i++){
        cs+=v[i];
        while(si<=i&&cs>tar){
            cs-=v[si];
            si++;
        }
        if(cs==tar){
            ans=max(ans,1LL*i-si+1);
        }
       }
        if(cs==tar){
            ans=max(ans,1LL*n-si);
        }
       if(ans==LLONG_MIN)return -1;
       return n-ans;
    }
};