#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> parents(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 0; i < parents.size(); ++i) {
      parents[i] = i;
    }
    for (auto edge : edges) {
      int src = find(parents, edge[0]);
      int dest = find(parents, edge[1]);
      if (src == dest) {
        return edge;
      } else {
        parents[dest] = src;
      }
    }
    return {};
  }
  int find(vector<int> &parents, int curr) {
    if (parents[curr] == curr) {
      return curr;
    } else {
      parents[curr] = find(parents, parents[curr]);
      return parents[curr];
    }
  }
  bool _union(vector<int> &parents, vector<int> &rank, int src, int dest) {
    src = find(parents, src);
    dest = find(parents, dest);
    if (src == dest) {
      return false;
    }
    if (rank[src] < rank[dest]) {
      swap(src, dest);
    }
    parents[dest] = src;
    rank[src]++;
    return true;
  }
};
