#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> readBinaryWatch(int turnedOn) {
    if (turnedOn == 0) return {"0:00"};
    if (turnedOn > 8) return {};

    std::vector<std::string> out{};
    int q{(1 << turnedOn) - 1};
    const int maxQ{1 << 10};
    while (q < maxQ) {
      const int h{q >> 6};
      const int m{q & 0b111111};
      if (h < 12 && m < 60) {
        std::string str(h >= 10 ? 5 : 4, ' ');

        std::size_t i{0};
        if (h >= 10) str[i++] = '0' + h / 10;
        str[i++] = '0' + h % 10;
        str[i++] = ':';
        str[i++] = '0' + m / 10;
        str[i++] = '0' + m % 10;

        out.push_back(std::move(str));
      }

      const int r{q & -q};
      const int n{q + r};
      q = (((n ^ q) >> 2) / r) | n;
    }

    return out;
  }
};
