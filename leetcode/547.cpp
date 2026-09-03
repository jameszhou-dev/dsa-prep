#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    vector<int> parents(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < parents.size(); ++i) {
      parents[i] = i;
    }
    for (int i = 0; i < isConnected.size(); ++i) {
      for (int j = 0; j < isConnected[i].size(); ++j) {
        if (isConnected[i][j] == 1) {
          _union(parents, rank, i, j);
        }
      }
    }
    unordered_set<int> provinces;
    for (int i = 0; i < parents.size(); ++i) {
      provinces.insert(find(parents, parents[i]));
    }
    return provinces.size();
  }
  int find(vector<int> &parents, int curr) {
    if (parents[curr] != curr) {
      parents[curr] = find(parents, parents[curr]);
    }
    return parents[curr];
  }
  void _union(vector<int> &parents, vector<int> &rank, int src, int dest) {
    src = find(parents, src);
    dest = find(parents, dest);
    if (rank[src] < rank[dest]) {
      swap(src, dest);
    }
    parents[dest] = src;
    rank[src]++;
  }
};
