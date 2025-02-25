#include <utility>
#include <vector>

class Solution {
 public:
  int numOfSubarrays(std::vector<int>& arr) {
    int count{0}, even{0}, first{0}, second{0};
    for (const auto num : arr) {
      if (num % 2 == 0) {
        ++even;
      } else {
        first += even + 1;
        std::swap(first, second);
        even = 0;
      }
      count = (count + second) % 1000000007;
    }
    return count;
  }
};
