class Solution {
public:
    bool isSubsequence(string s1, string s2) {
        int i = 0, j = 0;
        while (i < s1.length() && j < s2.length()) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }
        return i == s1.length();
    }

    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int maxLength = -1;
        
        for (int i = 0; i < n; i++) {
            bool uncommon = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                if (isSubsequence(strs[i], strs[j])) {
                    uncommon = false;
                    break;
                }
            }
            
            if (uncommon) {
                maxLength = max(maxLength, (int)strs[i].length());
            }
        }
        
        return maxLength;
    }
};