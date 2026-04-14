#include "leet.h"
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != temp) {
                return 1;
            }
        }
        return 0;
    }
};
