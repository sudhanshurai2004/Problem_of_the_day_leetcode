#include <vector>

class LUPrefix {
    vector<bool> uploaded;
    int longest_prefix;

public:
    LUPrefix(int n) {
        uploaded.resize(n + 1, false);
        longest_prefix = 0;
    }
    
    void upload(int video) {
        uploaded[video] = true;
        while (longest_prefix + 1 < uploaded.size() && uploaded[longest_prefix + 1]) {
            longest_prefix++;
        }
    }
    
    int longest() {
        return longest_prefix;
    }
};