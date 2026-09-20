class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int firstOne = -1, lastOne = -1;
        int maxGap = 0;
        int prevOne = -1;
        
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (firstOne == -1) firstOne = i;
                lastOne = i;
                if (prevOne != -1) {
                    maxGap = max(maxGap, (i - prevOne) / 2);
                }
                prevOne = i;
            }
        }
        
        return max({firstOne, n - 1 - lastOne, maxGap});
    }
};