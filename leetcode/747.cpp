using namespace std;
#include <algorithm>
#include <vector>

class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    int max_num = INT_MIN;
    int max_it = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > max_num) {
        max_num = nums[i];
        max_it = i;
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (i != max_it && nums[i] * 2 > max_num) {
        return -1;
      }
    }
    return max_it;
  }
};
