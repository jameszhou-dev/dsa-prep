#include <vector>
using namespace std;

class Solution {
public:
  vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  int countIslands(vector<vector<int>> &grid, int k) {
    int result = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] != 0 && dfs(grid, i, j) % k == 0) {
          result++;
        }
      }
    }
    return result;
  }
  long long dfs(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() ||
        grid[i][j] == 0) {
      return 0;
    }
    long long ret = grid[i][j];
    grid[i][j] = 0;
    for (auto direction : directions) {
      ret += dfs(grid, i + direction.first, j + direction.second);
    }
    return ret;
  }
};
