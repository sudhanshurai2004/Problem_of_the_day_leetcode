class Solution {
public:
using ll=long long;
    int findNthDigit(int n) {
      int k=n;
        ll dig=1LL;

        for( dig=1LL;dig<=15;dig++){
            ll hi=1LL*pow(10,dig)-1LL;
            ll lo=1LL*pow(10,dig-1);
            ll cnt=hi-lo+1;
            if(cnt*dig>=k)break;
            k-=cnt*dig;

        }
cout<<dig<<endl;
        ll val=(k+dig-1)/dig;
        ll lo=1LL*pow(10,dig-1);
        int p=lo+val-1;
        string x=to_string(p);
        cout<<x<<endl;
        k%=dig;
        if(k==0)k=dig;
        return x[k-1]-'0';

    }
};