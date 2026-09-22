class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int total_xor = 0;
        
       
        for (int i = 0; i < n; ++i) {
            total_xor ^= nums[i];
        }
        
        int max_val = (1 << maximumBit) - 1; 
        vector<int> ans(n);
        
       
        for (int i = 0; i < n; ++i) {
            
            ans[i] = total_xor ^ max_val;
            
           
            total_xor ^= nums[n - 1 - i];
        }
        
        return ans;
    }
};