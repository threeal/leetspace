#include <string>

const unsigned long mod = 1'000'000'009;

class Solution {
 public:
  int numberOfWays(std::string corridor) {
    unsigned long count = 1;

    unsigned char seats = 0;
    unsigned long plants = 0;

    for (const auto c : corridor) {
      if (seats < 2) {
        if (c == 'S') ++seats;
      } else {
        switch (c) {
          case 'S':
            if (plants > 0) count = (count * ++plants) % mod;
            plants = 0;
            seats = 1;
            break;

          case 'P':
            ++plants;
            break;
        }
      }
    }

    if (seats != 2) return 0;
    return count;
  }
};
