using namespace std;
#include <vector>

class Solution {
public:
  long long finishTime(int n, vector<vector<int>> &edges,
                       vector<int> &baseTime) {
    vector<vector<int>> adj(n);
    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }
    return dfs(adj, baseTime, 0);
  }

  long long dfs(vector<vector<int>> &adj, vector<int> &basetime, int curr) {
    if (adj[curr].empty())
      return basetime[curr];
    long long earliest = LLONG_MAX;
    long long latest = LLONG_MIN;
    for (int i = 0; i < adj[curr].size(); ++i) {
      long long ret = dfs(adj, basetime, adj[curr][i]);
      earliest = min(earliest, ret);
      latest = max(latest, ret);
    }
    long long finish = (latest - earliest) + basetime[curr];
    finish += latest;
    return finish;
  }
};
