using namespace std;
#include <vector>

class Solution {
public:
  int firstStableIndex(vector<int> &nums, int k) {
    vector<int> mins(nums.size());
    vector<int> maxs(nums.size());
    maxs[0] = nums[0];
    mins.back() = nums.back();
    for (int i = 1; i < nums.size(); ++i) {
      maxs[i] = max(maxs[i - 1], nums[i]);
    }
    for (int i = nums.size() - 2; i >= 0; --i) {
      mins[i] = min(mins[i + 1], nums[i]);
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (maxs[i] - mins[i] <= k) {
        return i;
      }
    }
    return -1;
  }
};
