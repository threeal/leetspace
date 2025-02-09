#include <cstring>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> restoreIpAddresses(std::string s) {
    std::string out(s.size() + 4, ' ');
    std::vector<std::string> output{};

    std::size_t a{}, b{}, c{};


    // for (std::size_t a{1}; a <= 3; ++a) {
    //   if (a + 3 > s.size()) break;
    //   if (a == 3) {
    //     if (s[0] > '2') continue;
    //     if (s[0] == '2') {
    //       if (s[1] > '5') continue;
    //       if (s[1] == '5' && s[2] > '5') continue;
    //     }
    //   }

    //   for (std::size_t b{1}; b <= 3; ++b) {
    //     if (a + b + 2 > s.size()) break;
    //     if (b == 3) {
    //       if (s[a] > '2') continue;
    //       if (s[a] == '2') {
    //         if (s[a + 1] > '5') continue;
    //         if (s[a + 1] == '5' && s[a + 2] > '5') continue;
    //       }
    //     }

    //     for (std::size_t c{1}; c <= 3; ++c) {
    //       if (a + b + c + 1 > s.size()) break;
    //       if (c == 3) {
    //         if (s[a + b] > '2') continue;
    //         if (s[a + b] == '2') {
    //           if (s[a + b + 1] > '5') continue;
    //           if (s[a + b + 1] == '5' && s[a + b + 2] > '5') continue;
    //         }
    //       }

    //       if (s.size() - a - b - c > 3) break;
    //       if (s.size() - a - b - c == 3) {
    //         if (s[a + b + c] > '2') continue;
    //         if (s[a + b + c] == '2') {
    //           if (s[a + b + c + 1] > '5') continue;
    //           if (s[a + b + c + 1] == '5' && s[a + b + c + 2] > '5') continue;
    //         }
    //       }

    //       std::string ss(s.size() + 4);


    //       if (c == 1 && s[a + b] == '0') break;
    //     }

    //     if (b == 1 && s[a] == '0') break;
    //   }

    //   if (a == 1 && s[0] == '0') break;
    // }
    return output;
  }
};
