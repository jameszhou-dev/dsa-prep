using namespace std;
#include <string>

class Solution {
public:
  string categorizeBox(int length, int width, int height, int mass) {
    bool bulky = (length >= 10000 || width >= 10000 || height >= 10000 ||
                  (double(length) * width * height >= 1000000000))
                     ? true
                     : false;
    bool heavy = (mass >= 100) ? true : false;
    if (bulky && heavy) {
      return "Both";
    } else if (bulky || heavy) {
      return bulky ? "Bulky" : "Heavy";
    } else {
      return "Neither";
    }
  }
};
