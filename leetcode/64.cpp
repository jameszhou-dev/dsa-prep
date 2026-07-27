#include <vector>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    for (int i = grid.size() - 1; i >= 0; --i) {
      for (int j = grid[i].size() - 1; j >= 0; --j) {
        int min_path = INT_MAX;
        if (i == grid.size() - 1 && j == grid[i].size() - 1)
          continue;
        else if (i == grid.size() - 1)
          grid[i][j] += grid[i][j + 1];
        else if (j == grid[i].size() - 1)
          grid[i][j] += grid[i + 1][j];
        else
          grid[i][j] += min(grid[i][j + 1], grid[i + 1][j]);
      }
    }
    return -1;
  }
};
