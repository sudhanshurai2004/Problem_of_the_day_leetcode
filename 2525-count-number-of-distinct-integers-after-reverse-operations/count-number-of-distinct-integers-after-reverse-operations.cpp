#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st;

        for (int num : nums) {
            st.insert(num);

            int rev = 0;
            int temp = num;
            while (temp > 0) {
                rev = rev * 10 + (temp % 10);
                temp /= 10;
            }

            st.insert(rev);
        }

        return st.size();
    }
};