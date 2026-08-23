using namespace std;
#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
  int longestSubsequence(string s, int k) {
    int i = s.size() - 1;
    int result = 0;
    int num = 0;
    while (i >= 0 && s[i] == '0') {
      i--;
      result++;
    }
    int start = -1;
    while (i >= 0) {
      if (s[i] == '1') {
        num <<= 1;
        num |= 1;
        if (num <= k) {
          result++;
          start = i;
        } else {
          break;
        }
      }
      i--;
    }
    while (start >= 0) {
      if (s[start] == '0') {
        result++;
      }
      start--;
    }
    return result;
  }
};
