#include <vector>
using namespace std;

class Solution {
public:
  vector<int> result;
  vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &grid) {
    vector<int> sums(grid.size());
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        sums[i] += j;
      }
    }
    vector<int> path;
    goodSubsetOfBinaryMatrix(sums, path, 0, 0);
    return result;
  }
  void goodSubsetOfBinaryMatrix(vector<int> &sums, vector<int> &path, int sum,
                                int index) {
    if (sum != 0 && sum <= path.size() / 2) {
      result = path;
      return;
    }
    if (path.size() == sums.size() || index >= sums.size()) {
      return;
    }
    path.push_back(index);
    goodSubsetOfBinaryMatrix(sums, path, sum + sums[index], index + 1);
    path.pop_back();
    goodSubsetOfBinaryMatrix(sums, path, sum, index + 1);
    path.pop_back();
  }
};
