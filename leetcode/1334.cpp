#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int findTheCity(int n, vector<vector<int>> &edges, int threshold) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; ++i) {
      dist[i][i] = 0;
    }
    for (auto edge : edges) {
      dist[edge[0]][edge[1]] = edge[2];
      dist[edge[1]][edge[0]] = edge[2];
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }
    int numReachable = INT_MAX;
    int city = -1;
    for (int i = 0; i < n; ++i) {
      int temp = 0;
      for (int j = 0; j < n; ++j) {
        if (dist[i][j] <= threshold && i != j) {
          temp++;
        }
      }
      if (temp <= numReachable) {
        numReachable = temp;
        city = i;
      }
    }
    return city;
  }
};
