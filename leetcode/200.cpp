#include <vector>
using namespace std;

class Solution {
public:
  vector<int> parents;
  vector<int> rank;
  int islands = 0;
  int numIslands(vector<vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int n = rows * cols;
    parents = vector<int>(n);
    rank = vector<int>(n, 0);
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          parents[i * cols + j] = i * cols + j;
          islands++;
        }
      }
    }
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          int curr = i * cols + j;
          if (i + 1 < rows && grid[i + 1][j] == '1') {
            _union(curr, (i + 1) * cols + j);
          }
          if (j + 1 < cols && grid[i][j + 1] == '1') {
            _union(curr, i * cols + (j + 1));
          }
        }
      }
    }
    return islands;
  }

  int find(int i) {
    if (i != parents[i]) {
      parents[i] = find(parents[i]);
    }
    return parents[i];
  }

  void _union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (rank[x] < rank[y]) {
      swap(x, y);
    }
    parents[y] = x;
    if (rank[x] == rank[y])
      rank[x]++;
    islands--;
  }
};
