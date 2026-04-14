#include <vector>
using namespace std;

class Solution {
public:
    bool canCreateAlloy(int budget, vector<vector<int>>&composition, vector<int>& stock, vector<int>& cost, int numAlloys) {
        for (int i = 0; i < composition.size(); i++) {
            long long temp_budget = budget;
            for (int j = 0; j < composition[i].size(); j++) {
                long long x = (long long)composition[i][j] * numAlloys;
                if (stock[j] >= x) {
                        continue;
                } else {
                    temp_budget -= (x - stock[j]) * (long long)cost[j];
                }
            }
            if (temp_budget >= 0) {
                return true;
            }
        }
        return false;
    }

 int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        long long low = 0;
        long long high = 2e8;
        long long ret = 0;
        while (low <= high) {
            long long mid = low + (high-low) / 2;
            if (canCreateAlloy(budget, composition, stock, cost, mid)) {
                low = mid + 1;
                ret = mid;
            } else {
                high = mid - 1;
            }
        }
        return ret;
    }
};

