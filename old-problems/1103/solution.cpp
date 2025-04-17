#include <vector>

class Solution {
 public:
  std::vector<int> distributeCandies(int candies, int num_people) {
    std::vector<int> output(num_people, 0);
    int i{0};
    while (i + 1 <= candies) {
      output[i % num_people] += i + 1;
      candies -= i + 1;
      ++i;
    }
    output[i % num_people] += candies;
    return output;
  }
};
