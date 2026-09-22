class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        
        for (int c = 1; c < n; ++c) {
            vector<int> diag;
            int i = 0, j = c;
            while (i < n && j < n) {
                diag.push_back(grid[i][j]);
                i++; j++;
            }
            sort(diag.begin(), diag.end());
            i = 0, j = c;
            int idx = 0;
            while (i < n && j < n) {
                grid[i][j] = diag[idx++];
                i++; j++;
            }
        }
        
        
        for (int r = 0; r < n; ++r) {
            vector<int> diag;
            int i = r, j = 0;
            while (i < n && j < n) {
                diag.push_back(grid[i][j]);
                i++; j++;
            }
            sort(diag.rbegin(), diag.rend());
            i = r, j = 0;
            int idx = 0;
            while (i < n && j < n) {
                grid[i][j] = diag[idx++];
                i++; j++;
            }
        }
        
        return grid;
    }
};