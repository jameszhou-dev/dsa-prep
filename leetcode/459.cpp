#include "../leet.h"

class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    string sub = "";
    char last = s.back();
    int i = 0;
    while (i < s.size()) {
      sub.push_back(s[i]);
      if (s[i] == last) {
        break;
      }
      ++i;
    }
    int num = 0;
    for (int i = 0; i + sub.size() <= s.size(); i += sub.size()) {
      if (s.substr(i, sub.size()) != sub)
        return false;
      num++;
    }
    return num > 1;
  }
};
