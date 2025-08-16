#include <limits>
#include <string>

class Solution {
 public:
  int maxDifference(std::string s, int k) {
    const int n = s.size();
    int maxDiff{std::numeric_limits<int>::min()};
    for (char a{'0'}; a <= '4'; ++a) {
      for (char b{'0'}; b <= '4'; ++b) {
        if (a == b) continue;

        int l{-1};
        int minPrev[4]{
            std::numeric_limits<int>::max(),
            std::numeric_limits<int>::max(),
            std::numeric_limits<int>::max(),
            std::numeric_limits<int>::max()};

        int prevA{0}, prevB{0};
        int countA{0}, countB{0};
        int prevStatus{0b00}, status{0b10};

        for (int r{0}; r < n; ++r) {
          if (s[r] == a) {
            ++countA;
            status ^= 0b10;
          } else if (s[r] == b) {
            ++countB;
            status ^= 0b01;
          }

          while (r - l >= k && countB - prevB >= 2) {
            if (prevA - prevB < minPrev[prevStatus]) {
              minPrev[prevStatus] = prevA - prevB;
            }

            ++l;
            if (s[l] == a) {
              ++prevA;
              prevStatus ^= 0b10;
            } else if (s[l] == b) {
              ++prevB;
              prevStatus ^= 0b01;
            }
          }

          if (minPrev[status] != std::numeric_limits<int>::max()) {
            if (countA - countB - minPrev[status] > maxDiff) {
              maxDiff = countA - countB - minPrev[status];
            }
          }
        }
      }
    }
    return maxDiff;
  }
};
