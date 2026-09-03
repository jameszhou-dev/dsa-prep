#include <vector>
using namespace std;

class Solution {
public:
  vector<int> parents;
  vector<int> rank;
  int removed = 0;
  int removeStones(vector<vector<int>> &stones) {
    int n = stones.size();
    parents = vector<int>(n * 2);
    rank = vector<int>(n * 2);
    for (auto stone : stones) {
      parents[stone[0]] = stone[0];
      parents[n + stone[1]] = n + stone[1];
      removed++;
    }
    for (int i = 0; i < parents.size(); ++i) {
    }
  }
  int find(int i) {
    if (parents[i] != i) {
      parents[i] = find(i);
    }
    return parents[i];
  }
  void _union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (rank[x] < rank[y])
      swap(x, y);
    parents[y] = x;
    if (rank[x] == rank[y])
      rank[x]++;
  }
};
