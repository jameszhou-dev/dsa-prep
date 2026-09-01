#include "../leet.h"

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    vector<bool> result;
    int maxCandy = *max_element(candies.begin(), candies.end());
    for (auto candy : candies) {
      candy + extraCandies >= maxCandy ? result.push_back(true)
                                       : result.push_back(false);
    }
    return result;
  }
};
