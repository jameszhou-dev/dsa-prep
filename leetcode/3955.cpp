#include <vector>
using namespace std;
class Solution {
public:
  vector<string> result;
  vector<string> generateValidStrings(int n, int k) {
    string curr = "";
    generateValidStrings(n, k, curr, 0);
    return result;
  }
  void generateValidStrings(int n, int k, string &curr, int cost) {
    if (curr.size() == n) {
      if (cost <= k) {
        result.push_back(curr);
      }
      return;
    }
    if (curr.empty() || curr.back() != '1') {
      curr.push_back('1');
      generateValidStrings(n, k, curr, cost + curr.size() - 1);
      curr.pop_back();
    }
    curr.push_back('0');
    generateValidStrings(n, k, curr, cost);
    curr.pop_back();
  }
};
