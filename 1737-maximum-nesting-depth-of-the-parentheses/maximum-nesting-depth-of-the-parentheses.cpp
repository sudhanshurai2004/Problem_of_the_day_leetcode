class Solution {
public:
    int maxDepth(string s) {
        int currentDepth = 0;
        int maxDepth = 0;

        for (char c : s) {
            if (c == '(') {
                currentDepth++;                 // Entering a new level
                maxDepth = max(maxDepth, currentDepth);  // Update max if needed
            } else if (c == ')') {
                currentDepth--;                 // Exiting one level
            }
        }

        return maxDepth;
    }
};