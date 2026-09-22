#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isValid(int mid, const vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            if (nums[left] + nums[right] > mid) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int low = nums.front() + nums.back();
        int high = nums[nums.size() - 2] + nums.back();
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isValid(mid, nums)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};