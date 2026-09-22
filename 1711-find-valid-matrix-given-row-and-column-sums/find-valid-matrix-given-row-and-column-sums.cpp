#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        int i = 0, j = 0;
        while (i < m && j < n) {
            int val = min(rowSum[i], colSum[j]);
            ans[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;

            if (rowSum[i] == 0) {
                i++;
            }
            if (colSum[j] == 0) {
                j++;
            }
        }

        return ans;
    }
};