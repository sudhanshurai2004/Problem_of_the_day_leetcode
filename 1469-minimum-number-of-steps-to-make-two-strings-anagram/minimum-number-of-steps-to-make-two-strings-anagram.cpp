#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
      
        vector<int> countS(26, 0);
        vector<int> countT(26, 0);
        
        for (char c : s) {
            countS[c - 'a']++;
        }
        for (char c : t) {
            countT[c - 'a']++;
        }
        
 
        int commonChars = 0;
        for (int i = 0; i < 26; i++) {
            commonChars += min(countS[i], countT[i]);
        }
        
        
        return s.length() - commonChars;
    }
};