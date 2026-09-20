class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string ans = "";
        
       
        for (char c : order) {
            if (freq[c - 'a'] > 0) {
                ans.append(freq[c - 'a'], c); 
                freq[c - 'a'] = 0;
            }
        }
       
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                ans.append(freq[i], char('a' + i));
            }
        }
        
        return ans;
    }
};