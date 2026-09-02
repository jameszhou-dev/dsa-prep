#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<int> degrees(n);
    set<pair<int, int>> rds;
    int result = INT_MIN;
    for (auto road : roads) {
      degrees[road[0]]++;
      degrees[road[1]]++;
      rds.insert({road[0], road[1]});
      rds.insert({road[1], road[0]});
    }
    for (int i = 0; i < degrees.size(); ++i) {
      for (int j = 0; j < degrees.size(); ++j) {
        if (i != j) {
          rds.count({i, j}) ? result = max(result, degrees[i] + degrees[j] - 1)
                            : result = max(result, degrees[i] + degrees[j]);
        }
      }
    }
    return result;
  }
};
