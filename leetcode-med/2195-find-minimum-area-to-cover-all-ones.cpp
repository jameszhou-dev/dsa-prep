#include <leet.h>
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minRow = grid.size();
        int maxRow = 0;
        int minCol = grid[0].size();
        int maxCol = 0; 
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    if (i < minRow) {
                        minRow = i;
                    } 
                    if (i > maxRow) {
                        maxRow = i;
                    }
                    if (j < minCol) {
                        minCol = j;
                    } 
                    if (j > maxCol) {
                        maxCol = j;
                    }
                }
            }
        }
        return (maxRow+1-minRow) * (maxCol + 1 - minCol);
    }
};