#include <string>
#include <map>

using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string sortVowels(string s) {
        map<char, int> vowelCount;
        
        for (char c : s) {
            if (isVowel(c)) {
                vowelCount[c]++;
            }
        }
        
        string result = s;
        auto it = vowelCount.begin();
        
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                result[i] = it->first;
                it->second--;
                if (it->second == 0) {
                    it++;
                }
            }
        }
        
        return result;
    }
};