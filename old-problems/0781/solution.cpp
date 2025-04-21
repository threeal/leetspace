#include <vector>

class Solution {
 public:
  int numRabbits(std::vector<int>& answers) {
    int freqs[1000]{0};
    for (const int answer : answers) ++freqs[answer];

    int num{0};
    for (int i{0}; i < 1000; ++i) {
      num += (i + 1) * ((freqs[i] + i) / (i + 1));
    }

    return num;
  }
};
