#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        vector<vector<int>> bucket(nums.size());
        for (const auto& [key, value] : freq) {
            bucket[value-1].push_back(key);
        }
        int index = bucket.size()-1;
        int count = 0;
        vector<int> result;
        while (index >= 0 && count < k) {
            int i = 0;
            count += bucket[index].size();
            while (i < bucket[index].size()) {
                result.push_back(bucket[index][i]);
                i++;
            }
            index--;
        }
        return result;
    }
};