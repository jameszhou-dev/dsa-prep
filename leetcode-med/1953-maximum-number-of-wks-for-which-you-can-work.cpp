#include <leet.h>
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int count = 0;
        int prev = -1;
        while (true) {
            if (milestones[0] == 0 || (prev == milestones[0] && milestones[1] == 0)) {
                break;
            }
            sort(milestones.begin(), milestones.end(), greater<int>());
            if (milestones[0] == prev) {
                milestones[1]--;
                prev = milestones[1];
            } else {
                milestones[0]--;
                prev = milestones[0];
            }
            count++;
        }
    }
};
