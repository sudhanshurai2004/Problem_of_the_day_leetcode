#include <string>

using namespace std;

class Solution {
public:
    string stringHash(string s, int k) {
        string result = "";
        int sum = 0;
        
        for (int i = 0; i < s.length(); i++) {
            sum += s[i] - 'a';
            
            if ((i + 1) % k == 0) {
                int hashedChar = sum % 26;
                result += (char)('a' + hashedChar);
                sum = 0;
            }
        }
        
        return result;
    }
};