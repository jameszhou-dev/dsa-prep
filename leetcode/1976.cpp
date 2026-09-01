#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto road : roads) {
      adj[road[0]].push_back({road[1], road[2]});
      adj[road[1]].push_back({road[0], road[2]});
    }
    vector<int> cost(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 0});
    vector<int> ways(n);
    cost[0] = 0;
    ways[0] = 1;
    while (!pq.empty()) {
      auto [weight, curr] = pq.top();
      pq.pop();
      for (auto neighbor : adj[curr]) {
        auto [n_curr, n_weight] = neighbor;
        if (weight + n_weight < cost[n_curr]) {
          cost[n_curr] = weight + n_weight;
          pq.push({cost[n_curr], n_curr});
          ways[n_curr] = ways[curr];
        } else if (weight + n_weight == cost[n_curr]) {
          ways[n_curr] += ways[curr];
        }
      }
    }
    return ways.back();
  }
};
