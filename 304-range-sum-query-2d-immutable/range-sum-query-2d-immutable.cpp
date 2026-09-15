class NumMatrix {
public:
    vector<vector<int>> ps;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        ps.assign(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ps[i + 1][j + 1] = matrix[i][j] + ps[i][j + 1] + ps[i + 1][j] - ps[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // 2D Prefix Sum formula
        return ps[row2 + 1][col2 + 1] - ps[row1][col2 + 1] - ps[row2 + 1][col1] + ps[row1][col1];
    }
};