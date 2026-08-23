using namespace std;
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  string largestWordCount(vector<string> &messages, vector<string> &senders) {
    unordered_map<string, int> wordCounts;
    for (int i = 0; i < messages.size(); ++i) {
      int count = 1;
      for (int j = 0; j < messages[i].size(); ++j) {
        if (messages[i][j] == ' ') {
          count++;
        }
      }
      wordCounts[senders[i]] += count;
    }
    pair<string, int> result = {"", 0};
    for (auto count : wordCounts) {
      if (count.second > result.second) {
        result = count;
      } else if (count.second == result.second) {
        count.first > result.first ? result = count : result = result;
      }
    }
    return result.first;
  }
};
