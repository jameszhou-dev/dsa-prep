#include <vector>
using namespace std;

class Solution {
public:
  vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                    vector<vector<int>> &queries) {
    vector<bool> result;
    for (auto query : queries) {
      if (abs(nums[query.front()] - nums[query.back()]) <= maxDiff) {
        result.push_back(true);
      } else {
        result.push_back(false);
      }
    }
    return result;
  }
};
