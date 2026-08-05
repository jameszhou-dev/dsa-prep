#include <vector>
using namespace std;
class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    vector<int> result(2);
    vector<bool> seen(grid.size() * grid.size(), false);
    for (auto i : grid) {
      for (auto j : i) {
        if (seen[j - 1]) {
          result.front() = j;
        } else {
          seen[j - 1] = !seen[j - 1];
        }
      }
    }
    for (int i = 0; i < seen.size(); ++i) {
      if (!seen[i]) {
        result.back() = i + 1;
        break;
      }
    }
    return result;
  }
};
