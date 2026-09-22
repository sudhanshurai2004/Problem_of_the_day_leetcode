#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> answer(m);
        
        for (int i = 0; i < m; i++) {
            vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(sub.begin(), sub.end());
            
            bool isArithmetic = true;
            int diff = sub[1] - sub[0];
            
            for (int j = 2; j < sub.size(); j++) {
                if (sub[j] - sub[j - 1] != diff) {
                    isArithmetic = false;
                    break;
                }
            }
            
            answer[i] = isArithmetic;
        }
        
        return answer;
    }
};