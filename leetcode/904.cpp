#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    pair<int, int> b1 = {-1, -1};
    pair<int, int> b2 = {-1, -1};
    int start = 0;
    int i = 0;
    int result = INT_MIN;
    while (i < fruits.size()) {
      if (b1.first == fruits[i]) {
        b1 = {b1.first, b1.second + 1};
      } else if (b2.first == fruits[i]) {
        b2 = {b2.first, b2.second + 1};
      } else if (b1.first == -1) {
        b1 = {fruits[i], 1};
      } else if (b2.first == -1) {
        b2 = {fruits[i], 1};
      } else {
        while (b1.second != 0 && b2.second != 0 && start <= i) {
          if (fruits[start++] == b1.first) {
            b1 = {b1.first, b1.second - 1};
          } else {
            b2 = {b2.first, b2.second - 1};
          }
        }
        if (b1.second == 0) {
          b1 = {fruits[i], 1};
        } else {
          b2 = {fruits[i], 1};
        }
      }
      result = max(result, i - start + 1);
      ++i;
    }
    return result;
  }
};
