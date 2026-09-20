class Solution {
public:
    bool canTransform(string s1, string s2) {
        if(s1.size()!=s2.size())return 0;
        int n=s1.size();
   
        int cnt1=0,cnt2=0;
        int gap=0;
        string v1,v2;
        int r1=0,r2=0,l1=0,l2=0;
        for(int i=0;i<n;i++){
if(s1[i]=='X')cnt1++;
if(s2[i]=='X')cnt2++;

if(s1[i]=='L'){
v1+=s1[i];
gap++;
l1++;
}
if(s1[i]=='R'){
v1+=s1[i];
r1++;
gap--;
}
if(s2[i]=='L'){
v2+=s2[i];
l2++;
gap--;
}
if(s2[i]=='R'){
v2+=s2[i];
r2++;
gap++;
}
if(cnt2+gap>cnt1)return 0;
if(r2>r1||l2<l1)return 0;
        }
       if(v1!=v2)return 0;
       return 1; 
    }
};