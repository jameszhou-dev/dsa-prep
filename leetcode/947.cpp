#include <vector>
using namespace std;

class Solution {
public:
  vector<int> parents;
  vector<int> rank;
  int nodes = 0;
  int removeStones(vector<vector<int>> &stones) {
    int n = 10001;
    parents = vector<int>(n * 2, INT_MIN);
    rank = vector<int>(n * 2);
    for (auto stone : stones) {
      if (parents[stone[0]] == INT_MIN) {
        parents[stone[0]] = stone[0];
        nodes++;
      }
      if (parents[n + stone[1]] == INT_MIN) {
        parents[n + stone[1]] = n + stone[1];
        nodes++;
      }
    }
    for (auto stone : stones) {
      _union(stone[0], n + stone[1]);
    }
    return stones.size() - nodes;
  }
  int find(int i) {
    if (parents[i] != i) {
      parents[i] = find(parents[i]);
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
    nodes--;
    if (rank[x] == rank[y])
      rank[x]++;
  }
};
