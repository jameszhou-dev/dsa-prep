#include "../leet.h"

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    obstacleGrid[0][0] ? obstacleGrid[0][0] = 0 : obstacleGrid[0][0] = 1;
    for (int i = 0; i < obstacleGrid.size(); ++i) {
      for (int j = 0; j < obstacleGrid[i].size(); ++j) {
        if (i == 0 && j == 0)
          continue;
        if (obstacleGrid[i][j] == 1) {
          obstacleGrid[i][j] = 0;
        } else {
          if (i == 0)
            obstacleGrid[i][j] = obstacleGrid[i][j - 1];
          else if (j == 0)
            obstacleGrid[i][j] = obstacleGrid[i - 1][j];
          else
            obstacleGrid[i][j] =
                obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
        }
      }
    }
    return obstacleGrid.back().back();
  }
};
