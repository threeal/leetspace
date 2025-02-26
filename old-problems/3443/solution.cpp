#include <string>

class Solution {
 public:
  int maxDistance(std::string str, int k) {
    int maxDist{0}, n{0}, s{0}, e{0}, w{0};
    for (const auto c : str) {
      switch (c) {
        case 'N':
          ++n;
          break;

        case 'S':
          ++s;
          break;

        case 'E':
          ++e;
          break;

        case 'W':
          ++w;
          break;
      }

      const int minh = n < s ? n : s;
      const int maxh = n >= s ? n : s;
      const int minw = e < w ? e : w;
      const int maxw = e >= w ? e : w;
      const int fix = minh + minw <= k ? minh + minw : k;
      const int dist = maxh + maxw - minh - minw + 2 * fix;
      if (dist > maxDist) maxDist = dist;
    }
    return maxDist;
  }
};
