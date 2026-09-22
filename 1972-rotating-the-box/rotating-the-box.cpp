#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for (int i = 0; i < m; i++) {
            int count = 0;
            int lastBoundary = n;
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '#') {
                    count++;
                    boxGrid[i][j] = '.';
                } else if (boxGrid[i][j] == '*') {
                    for (int k = 1; k <= count; k++) {
                        boxGrid[i][lastBoundary - k] = '#';
                    }
                    count = 0;
                    lastBoundary = j;
                }
            }
            for (int k = 1; k <= count; k++) {
                boxGrid[i][lastBoundary - k] = '#';
            }
        }

        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][i] = boxGrid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(res[i].begin(), res[i].end());
        }

        return res;
    }
};