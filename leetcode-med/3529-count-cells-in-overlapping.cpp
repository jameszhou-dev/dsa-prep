#include <leet.h>
class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        string grid_str = "";
        vector<pair<int, int>> ixs;
        set<pair<int, int>> common_ixs;
        set<pair<int, int>> res;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                grid_str += grid[i][j];
                pair<int, int> temp(i, j);
                ixs.push_back(temp);
            }
        }
        
        for (int i = 0; i < grid_str.length() - pattern.length() + 1; i++) {
            if (grid_str.substr(i, pattern.length()) == pattern) {
                for (int j = i; j < i + pattern.length(); j++) {
                    common_ixs.insert(ixs[j]);
                }
            }
        }
        grid_str = "";
        ixs = {};
        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                grid_str += grid[j][i];
                pair<int, int> temp(j, i);
                ixs.push_back(temp);
            }
        }
        for (int i = 0; i < grid_str.length() - pattern.length() + 1; i++) {
            if (grid_str.substr(i, pattern.length()) == pattern) {
                for (int j = i; j < i + pattern.length(); j++) {
                    if (common_ixs.find(ixs[j]) != common_ixs.end()) {
                        res.insert(ixs[j]);
                    }
                }
            }
        }
    
        return res.size();
    }
};