#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int length = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int result = INT_MAX;
    int right = 0;
    for (int left = 0; left < nums.size(); ++left) {
      while (right < nums.size() && nums[right] < nums[left] + length) {
        right++;
      }
      result = min(result, length - (right - left));
    }
    return result;
  }
};
