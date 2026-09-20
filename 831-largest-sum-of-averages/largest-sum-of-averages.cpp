class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefixSum[i] / i;
        }
        
        for (int j = 2; j <= k; j++) {
            for (int i = j; i <= n; i++) {
                for (int l = j - 1; l < i; l++) {
                    dp[i][j] = max(dp[i][j], dp[l][j - 1] + (prefixSum[i] - prefixSum[l]) / (i - l));
                }
            }
        }
        
        double maxScore = 0;
        for (int j = 1; j <= k; j++) {
            maxScore = max(maxScore, dp[n][j]);
        }
        
        return maxScore;
    }
};