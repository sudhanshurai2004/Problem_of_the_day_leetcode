class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(), piles.rend());
        
        int n = piles.size() / 3;
        int total_coins = 0;
        
        
        for (int i = 1; i < 2 * n; i += 2) {
            total_coins += piles[i];
        }
        
        return total_coins;
    }
};