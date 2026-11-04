#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n, 1e18);

        multiset<pair<long long, int>> left_half, right_half;
        long long s1 = 0, s2 = 0;

        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            
            if (left_half.empty() || val <= prev(left_half.end())->first) {
                left_half.insert({val, i});
                s1 += val;
            } else {
                right_half.insert({val, i});
                s2 += val;
            }

            if (i >= x) {
                long long rem_val = nums[i - x];
                int rem_idx = i - x;
                if (left_half.find({rem_val, rem_idx}) != left_half.end()) {
                    left_half.erase({rem_val, rem_idx});
                    s1 -= rem_val;
                } else if (right_half.find({rem_val, rem_idx}) != right_half.end()) {
                    right_half.erase({rem_val, rem_idx});
                    s2 -= rem_val;
                }
            }

            while (left_half.size() < right_half.size()) {
                auto it = right_half.begin();
                long long v = it->first;
                int idx = it->second;
                right_half.erase(it);
                s2 -= v;
                left_half.insert({v, idx});
                s1 += v;
            }
            while (left_half.size() > right_half.size() + 1) {
                auto it = prev(left_half.end());
                long long v = it->first;
                int idx = it->second;
                left_half.erase(it);
                s1 -= v;
                right_half.insert({v, idx});
                s2 += v;
            }

            if (i >= x - 1) {
                long long median = prev(left_half.end())->first;
                long long sz1 = left_half.size();
                long long sz2 = right_half.size();
                cost[i] = (median * sz1 - s1) + (s2 - median * sz2);
            }
        }

        vector<long long> prev_dp(n, 1e18), curr_dp(n, 1e18);

        long long min_so_far = 1e18;
        for (int i = x - 1; i < n; ++i) {
            min_so_far = min(min_so_far, cost[i]);
            prev_dp[i] = min_so_far;
        }

        for (int j = 2; j <= k; ++j) {
            fill(curr_dp.begin(), curr_dp.end(), 1e18);
            for (int i = j * x - 1; i < n; ++i) {
                curr_dp[i] = curr_dp[i - 1];
                if (prev_dp[i - x] != 1e18 && cost[i] != 1e18) {
                    curr_dp[i] = min(curr_dp[i], prev_dp[i - x] + cost[i]);
                }
            }
            prev_dp = curr_dp;
        }

        return prev_dp[n - 1];
    }
};