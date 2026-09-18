#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void update(int idx, int val, vector<int>& bit, int n) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int findKthEmpty(int k, vector<int>& bit, int n) {
        int idx = 0;
        int mask = 1;
        while (mask <= n) mask <<= 1;
        mask >>= 1;

        for (int len = mask; len != 0; len >>= 1) {
            if (idx + len <= n && bit[idx + len] < k) {
                idx += len;
                k -= bit[idx];
            }
        }
        return idx;
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        vector<int> bit(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            update(i, 1, bit, n);
        }

        vector<vector<int>> ans(n);

        for (auto& p : people) {
            int spaces = p[1] + 1;
            int idx = findKthEmpty(spaces, bit, n);
            
            ans[idx] = p;
            update(idx, -1, bit, n);
        }

        return ans;
    }
};