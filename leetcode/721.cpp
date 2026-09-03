#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>>
  accountsMerge(std::vector<std::vector<std::string>> &accounts) {
    unordered_map<string, string> names;
    unordered_map<string, string> parents;
    for (int i = 0; i < accounts.size(); ++i) {
      for (int j = 1; j < accounts[i].size(); ++j) {
        parents[accounts[i][j]] = accounts[i][j];
        names[accounts[i][j]] = accounts[i][0];
      }
    }
    for (int i = 0; i < accounts.size(); ++i) {
      string parent = find(parents, accounts[i][1]);
      for (int j = 2; j < accounts[i].size(); ++j) {
        parents[find(parents, accounts[i][j])] = parent;
      }
    }
    unordered_map<string, set<string>> Union;
    for (auto parent : parents) {
      Union[find(parents, parent.second)].insert(parent.first);
    }
    vector<vector<string>> result;
    cout << Union.size();
    for (auto i : Union) {
      vector<string> account;
      account.push_back(names[i.first]);
      account.insert(account.end(), i.second.begin(), i.second.end());
      result.push_back(account);
    }
    return result;
  }
  string find(unordered_map<string, string> &parents, string curr) {
    return parents[curr] == curr ? curr : find(parents, parents[curr]);
  }
};
