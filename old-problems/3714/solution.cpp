#include <unordered_map>
#include <vector>

class Solution {
 public:
  int longestBalanced(std::string s) {
    std::size_t longest{0};

    std::size_t prevA{0}, prevB{0}, prevC{0};

    int ab{0}, ac{0}, bc{0};
    std::unordered_map<int, std::size_t> abs{}, acs{}, bcs{};
    abs.emplace(0, 0);
    acs.emplace(0, 0);
    bcs.emplace(0, 0);

    long long a{0}, b{0}, c{0};
    std::unordered_map<long long, std::size_t> abcs{};
    abcs.emplace(0, 0);

    for (std::size_t i{0}; i < s.size(); ++i) {
      if (s[i] == 'a') {
        if (i + 1 - prevA > longest) longest = i + 1 - prevA;
        ++ab, ++ac, bc = 0, ++a;

        bcs.clear();
        bcs.emplace(0, i + 1);
      } else {
        prevA = i + 1;
      }

      if (s[i] == 'b') {
        if (i + 1 - prevB > longest) longest = i + 1 - prevB;
        --ab, ac = 0, ++bc, ++b;

        acs.clear();
        acs.emplace(0, i + 1);
      } else {
        prevB = i + 1;
      }

      if (s[i] == 'c') {
        if (i + 1 - prevC > longest) longest = i + 1 - prevC;
        ab = 0, --ac, --bc, ++c;

        abs.clear();
        abs.emplace(0, i + 1);
      } else {
        prevC = i + 1;
      }

      if (s[i] == 'a' || s[i] == 'b') {
        const auto it = abs.find(ab);
        if (it != abs.end()) {
          if (i + 1 - it->second > longest) longest = i + 1 - it->second;
        } else {
          abs.emplace(ab, i + 1);
        }
      }

      if (s[i] == 'a' || s[i] == 'c') {
        const auto it = acs.find(ac);
        if (it != acs.end()) {
          if (i + 1 - it->second > longest) longest = i + 1 - it->second;
        } else {
          acs.emplace(ac, i + 1);
        }
      }

      if (s[i] == 'b' || s[i] == 'c') {
        const auto it = bcs.find(bc);
        if (it != bcs.end()) {
          if (i + 1 - it->second > longest) longest = i + 1 - it->second;
        } else {
          bcs.emplace(bc, i + 1);
        }
      }

      long long key{(b - a) << 32 | (c - a)};
      const auto it = abcs.find(key);
      if (it != abcs.end()) {
        if (i + 1 - it->second > longest) longest = i + 1 - it->second;
      } else {
        abcs.emplace(key, i + 1);
      }
    }

    return longest;
  }
};
