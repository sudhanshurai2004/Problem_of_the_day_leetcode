#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isPossible(std::vector<int>& nums) {
        std::unordered_map<int, int> freq, tail;
        
        for (int x : nums) {
            freq[x]++;
        }
        
        for (int x : nums) {
            if (freq[x] == 0) continue;
            
            if (tail[x - 1] > 0) {
                tail[x - 1]--;
                tail[x]++;
            } 
            else if (freq[x + 1] > 0 && freq[x + 2] > 0) {
                freq[x + 1]--;
                freq[x + 2]--;
                tail[x + 2]++;
            } 
            else {
                return false;
            }
            
            freq[x]--;
        }
        
        return true;
    }
};