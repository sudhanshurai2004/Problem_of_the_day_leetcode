class Solution {
public:
const int mod=1e9+7;
const int MOD=1e9+7;
pair<long long ,long long> f(long long n){
    if(n==0)return {0,1};
    auto p=f(n>>1);
    long long a=p.first;
    long long b=p.second;
    //core formula by sudhanshu
    long long c = (a * (2 * b % MOD - a + MOD)) % MOD; // F(2k)
    long long d = (a * a % MOD + b * b % MOD) % MOD;
    if(n&1)return {d,(c+d)%mod};
    return {c,d};
}
    int countGoodStrings(long long n) {
      
        
        return (2*f(n).first)%mod;
    }
};