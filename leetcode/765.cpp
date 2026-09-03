#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSwapsCouples(vector<int> &row) {
    int n = row.size();
    vector<int> parents(n);
    for (int i = 0; i < row.size(); ++i) {
      parents[i] = i / 2;
      cout << parents[i] << " ";
    }
    return -1;
  }
};
