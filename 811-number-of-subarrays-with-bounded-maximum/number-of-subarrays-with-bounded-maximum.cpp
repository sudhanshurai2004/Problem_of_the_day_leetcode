class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }

private:
    int count(vector<int>& nums, int bound) {
        int ans = 0, currentCount = 0;
        for (int x : nums) {
            if (x <= bound) {
                currentCount++;
                ans += currentCount;
            } else {
                currentCount = 0;
            }
        }
        return ans;
    }
};