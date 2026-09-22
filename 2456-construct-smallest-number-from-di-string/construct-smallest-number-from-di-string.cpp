#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    bool solve(int idx, string& pattern, vector<bool>& used, string& current, string& result) {
        if (idx == pattern.length() + 1) {
            result = current;
            return true;
        }

        for (int digit = 1; digit <= 9; digit++) {
            if (!used[digit]) {
                if (idx == 0) {
                    used[digit] = true;
                    current.push_back(digit + '0');
                    
                    if (solve(idx + 1, pattern, used, current, result)) return true;
                    
                    current.pop_back();
                    used[digit] = false;
                } else {
                    int prevDigit = current.back() - '0';
                    char cond = pattern[idx - 1];

                    if ((cond == 'I' && digit > prevDigit) || (cond == 'D' && digit < prevDigit)) {
                        used[digit] = true;
                        current.push_back(digit + '0');

                        if (solve(idx + 1, pattern, used, current, result)) return true;

                        current.pop_back();
                        used[digit] = false;
                    }
                }
            }
        }
        return false;
    }

public:
    string smallestNumber(string pattern) {
        vector<bool> used(10, false);
        string current = "";
        string result = "";
        
        solve(0, pattern, used, current, result);
        
        return result;
    }
};