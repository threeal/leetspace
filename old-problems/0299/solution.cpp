#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class Solution {
 public:
  std::string getHint(std::string secret, std::string guess) {
    std::vector<int> missingSecret(10, 0);
    std::vector<int> missingGuess(10, 0);

    int bulls{0};
    for (int i = secret.size() - 1; i >= 0; --i) {
      if (secret[i] == guess[i]) {
        ++bulls;
      } else {
        ++missingSecret[secret[i] - '0'];
        ++missingGuess[guess[i] - '0'];
      }
    }

    int cows{0};
    for (int i{9}; i >= 0; --i) {
      cows += std::min(missingSecret[i], missingGuess[i]);
    }

    std::stringstream ss{};
    ss << bulls << "A" << cows << "B";
    return ss.str();
  }
};
