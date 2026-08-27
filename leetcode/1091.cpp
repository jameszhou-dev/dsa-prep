#include "../leet.h"

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    if (grid.front().front() == 1)
      return -1;
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1},  {-1, 0}, {1, 0},
                                         {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    q.push({0, 0});
    int steps = 0;
    while (!q.empty()) {
      steps++;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        pair<int, int> curr = q.front();
        if (curr.first == grid.size() - 1 &&
            curr.second == grid[0].size() - 1) {
          return steps;
        }
        q.pop();
        for (auto direction : directions) {
          pair<int, int> next = {curr.first + direction.first,
                                 curr.second + direction.second};
          if (next.first >= 0 && next.first < grid.size() && next.second >= 0 &&
              next.second < grid[0].size() &&
              grid[next.first][next.second] == 0) {
            q.push(next);
            grid[next.first][next.second] = 1;
          }
        }
      }
    }
    return -1;
  }
};
