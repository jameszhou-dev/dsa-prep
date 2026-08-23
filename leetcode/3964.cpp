using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
  int minLights(vector<int> &lights) {
    int i = 0;
    while (i < lights.size()) {
      if (lights[i] > 0) {
        int start = max(0, i - lights[i]);
        int end = min(i + lights[i], (int)lights.size() - 1);
        int new_index = lights.size();
        for (int j = start; j <= end; ++j) {
          if (lights[j] == 0) {
            lights[j] = -1;
            new_index = j;
          }
        }
        if (new_index == lights.size() - 1) {
          break;
        }
        i = new_index;
      } else {
        ++i;
      }
    }
    for (auto light : lights) {
      cout << light << endl;
    }
    int result = 0;
    i = 0;
    while (i < lights.size()) {
      if (lights[i] == 0) {
        result++;
        i += 3;
      } else {
        i++;
      }
    }
    return result;
  }
};
