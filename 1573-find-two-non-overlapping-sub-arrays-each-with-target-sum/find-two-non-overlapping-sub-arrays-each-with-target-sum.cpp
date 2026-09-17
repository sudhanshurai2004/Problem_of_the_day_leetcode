class Solution {
public:
    int minSumOfLengths(vector<int>&v, int tg) {
        int n=v.size();
        vector<int>l(n),r(n);
        int len=INT_MAX;
        map<int,int>mp1,mp2;
        mp1[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
sum+=v[i];
if(mp1.find(sum-tg)!=mp1.end()){
    len=min(len,i-mp1[sum-tg]);
}
mp1[sum]=i;
l[i]=len;
        }


        len=INT_MAX;
         mp2[0]=n;
        sum=0;

        for(int i=n-1;i>=0;i--){
sum+=v[i];
if(mp2.find(sum-tg)!=mp2.end()){
    len=min(len,abs(i-mp2[sum-tg]));
}
mp2[sum]=i;
r[i]=len;
        }
int ans=INT_MAX;
for(int i=0;i<n-1;i++){
    if(l[i]==INT_MAX||r[i+1]==INT_MAX)continue;
    ans=min(ans,l[i]+r[i+1]);

}
return (ans>n)?-1:ans;
    }
};