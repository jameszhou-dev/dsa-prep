#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); i++) {
            m.insert({list1[i], i});
        }
        unordered_map<int, vector<string>> t;
        for (int i = 0; i < list2.size(); i++) {
            if (m.find(list2[i]) != m.end()) {
                int add_index = i + m[list2[i]];
                if (t.find(add_index) != t.end()) {
                    t[add_index].push_back(list2[i]);
                } else {
                    t.insert({add_index, {list2[i]}});
                }
            }
        }
        int min = list1.size() + list2.size();
        for (const auto& [key, value] : t) {
            if (key < min) {
                min = key;
            }
        }
        return t[min];
    }
};