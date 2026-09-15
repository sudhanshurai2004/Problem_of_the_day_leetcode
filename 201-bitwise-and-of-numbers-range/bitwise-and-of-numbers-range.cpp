class Solution {
public:
    int rangeBitwiseAnd(int l,int r) {
        int ans=0;
        for(int i=0;i<31;i++){
            if(((1<<i)&l)&&((1<<i)&r)){
                int diff=r-l+1;
                if(diff<=(1<<i))ans|=(1<<i);
            }
        }
        return ans;
    }
};