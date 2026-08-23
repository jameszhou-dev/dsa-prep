using namespace std;
#include <vector>

class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;
    while (left <= right) {
      int num = left;
      while (num != 0) {
        int digit = num % 10;
        if (digit == 0 || left % digit != 0) {
          break;
        }
        num /= 10;
      }
      if (num == 0) {
        result.push_back(left);
      }
      left++;
    }
    return result;
  }
};
