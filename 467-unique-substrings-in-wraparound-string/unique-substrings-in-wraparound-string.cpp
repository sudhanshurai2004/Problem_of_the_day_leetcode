class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> count(26, 0);
        int current_len = 0;
        
        for (int i = 0; i < s.length(); i++) {
           
            if (i > 0 && (s[i] - s[i - 1] == 1 || s[i - 1] - s[i] == 25)) {
                current_len++;
            } else {
                current_len = 1;
            }
            
            int idx = s[i] - 'a';
            count[idx] = max(count[idx], current_len);
        }
        
        int total_substrings = 0;
        for (int len : count) {
            total_substrings += len;
        }
        
        return total_substrings;
    }
};