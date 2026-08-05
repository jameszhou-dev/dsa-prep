#include <vector>
using namespace std;
class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;
    int result = INT_MAX;
    while (l <= r) {
      while (l < r && nums[l] == nums[r]) {
        l++;
      }
      int mid = l + (r - l) / 2;
      result = min(result, nums[mid]);
      if (nums[r] < nums[mid]) {
        l = ++mid;
      } else {
        r = --mid;
      }
    }
    return result;
  }
};
