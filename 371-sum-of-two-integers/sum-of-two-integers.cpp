class Solution {
public:
    int getSum(int a, int b) {
    int ans=0, cin=0;
    for(int i=0;i<32;i++){
        int ba=(a&1);
        int bb=(b&1);
a>>=1;
b>>=1;
int b=ba^bb^cin;
ans|=(b<<i);
cin=(ba&bb)|(bb&cin)|(ba&cin);
    }
return ans;
    }
};