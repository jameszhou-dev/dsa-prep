using namespace std;
#include <vector>

class Solution {
public:
  long long largestPerimeter(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<long long> sums = {0};
    for (int i = 1; i < nums.size(); ++i) {
      sums.push_back(sums.back() + nums[i - 1]);
    }
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (sums[i] > nums[i]) {
        return sums[i] + nums[i];
      }
    }
    return -1;
  }
};
