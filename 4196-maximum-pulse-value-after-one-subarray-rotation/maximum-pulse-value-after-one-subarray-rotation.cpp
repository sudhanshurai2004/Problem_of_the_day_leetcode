#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    long long maxValue(std::vector<int>& nums) {
        int n = nums.size();
        long long total_old = 0;
        std::vector<long long> P(n);
        
        for (int k = 0; k < n; ++k) {
            P[k] = (k % 2 == 0) ? nums[k] : -nums[k];
            total_old += P[k];
        }
        
        long long pref = 0;
        long long min_diff = LLONG_MAX;
        long long max_even = LLONG_MIN;
        long long max_odd = 0;
        
        for (int R = 0; R < n; ++R) {
            pref += P[R];
            int parity = R % 2;
            
            if (parity == 0) {
                if (max_even != LLONG_MIN) {
                    min_diff = std::min(min_diff, pref - max_even);
                }
                max_even = std::max(max_even, pref);
            } else {
                min_diff = std::min(min_diff, pref - max_odd);
                max_odd = std::max(max_odd, pref);
            }
        }
        
        long long ans = total_old;
        if (min_diff != LLONG_MAX) {
            ans = std::max(total_old, total_old - 2 * min_diff);
        }
        
        return ans;
    }
};