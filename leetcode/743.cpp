#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> cost(n + 1, INT_MAX);
    for (auto edge : times) {
      adj[edge[0]].push_back({edge[1], edge[2]});
    }
    cost[k] = 0;
    cost[0] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, k});
    while (!pq.empty()) {
      int curr = pq.top().second;
      int d = pq.top().first;
      pq.pop();
      if (d > cost[curr]) {
        continue;
      }
      for (auto [neighbor, neighbor_d] : adj[curr]) {
        if (d + neighbor_d < cost[neighbor]) {
          cost[neighbor] = d + neighbor_d;
          pq.push({cost[neighbor], neighbor});
        }
      }
    }
    int result = -1;
    for (auto i : cost) {
      if (i == INT_MAX) {
        return -1;
      }
      result = max(result, i);
    }
    return result;
  }
};
