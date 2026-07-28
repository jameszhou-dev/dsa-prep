#include "../leet.h"

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false));
    for (int i = 0; i < s.size(); ++i) {
      dp[i][0] = true;
      dp[i][1] = true;
    }
    int start = 0;
    int len = 1;
    for (int j = 2; j <= s.size(); ++j) {
      for (int i = 0; i <= s.size() - j; ++i) {
        if (dp[i + 1][j - 2] && s[i] == s[i + j - 1]) {
          dp[i][j] = true;
          start = i;
          len = j;
        }
      }
    }
    return s.substr(start, len);
  }
};
