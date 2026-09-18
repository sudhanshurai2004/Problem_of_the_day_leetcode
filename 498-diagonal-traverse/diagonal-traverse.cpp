class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> elements;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                elements.push_back({i + j, i, j});
            }
        }
        
        sort(elements.begin(), elements.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            if (a[0] % 2 == 0) {
                return a[1] > b[1]; 
            } else {
                return a[1] < b[1];
            }
        });
        
        vector<int> result;
        for (auto& el : elements) {
            result.push_back(mat[el[1]][el[2]]);
        }
        
        return result;
    }
};