class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int r = rStart, c = cStart;
        
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            result.push_back({r, c});
        }
        
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        
        int len = 0;
        int d = 0;
        
        while (result.size() < rows * cols) {
            if (d == 0 || d == 2) {
                len++;
            }
            
            for (int step = 0; step < len; ++step) {
                r += dr[d];
                c += dc[d];
                
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    result.push_back({r, c});
                }
            }
            
            d = (d + 1) % 4;
        }
        
        return result;
    }
};