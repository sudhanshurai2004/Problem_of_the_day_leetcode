#include <vector>

using namespace std;

class SubrectangleQueries {
    vector<vector<int>> mat;

public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        mat = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
       
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                mat[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
     
        return mat[row][col];
    }
};