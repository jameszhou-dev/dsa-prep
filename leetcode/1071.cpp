#include "../leet.h"

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    string result = "";
    int size = 1;
    if (str1.size() < str2.size())
      swap(str1, str2);
    while (size <= str2.size()) {
      if (str1.size() % size == 0 && str2.size() % size == 0) {
        string curr = str2.substr(0, size);
        bool valid = true;
        for (int i = 0; i + size <= str1.size(); i += size) {
          if ((i + size <= str2.size() && curr != str2.substr(i, size)) ||
              curr != str1.substr(i, size)) {
            valid = false;
            break;
          }
        }
        if (valid) {
          result = curr;
        }
      }
      size++;
    }
    return result;
  }
};
