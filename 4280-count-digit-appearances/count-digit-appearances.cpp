#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int total_count = 0;
        char target = '0' + digit;
        for (int num : nums) {
            string s = to_string(num);
            total_count += count(s.begin(), s.end(), target);
        }
        return total_count;
    }
};