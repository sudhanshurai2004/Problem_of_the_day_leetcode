class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int current_xor = 0;
for (int num : nums) current_xor ^= num;
return __builtin_popcount(current_xor ^ k);
    }
};