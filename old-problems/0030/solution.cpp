#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> findSubstring(
      std::string s, std::vector<std::string>& words) {
    std::string_view sv(s);
    std::size_t wordSize{words[0].size()};

    std::unordered_map<std::string_view, int> freqs{};
    for (const auto& word : words) ++freqs[word];

    std::vector<int> output{};
    for (std::size_t start{0}; start < wordSize; ++start) {
      std::size_t count{words.size()}, l{start + wordSize}, r{start + wordSize};
      while (r <= sv.size()) {
        const auto it = freqs.find(sv.substr(r - wordSize, wordSize));
        if (it == freqs.end()) {
          while (l < r) {
            ++freqs[sv.substr(l - wordSize, wordSize)];
            ++count;
            l += wordSize;
          }
          l += wordSize;
        } else {
          while (it->second == 0) {
            ++freqs[sv.substr(l - wordSize, wordSize)];
            ++count;
            l += wordSize;
          }

          --it->second;
          if (--count == 0) {
            output.push_back(r - words.size() * wordSize);
          }
        }
        r += wordSize;
      }

      while (l < r) {
        ++freqs[sv.substr(l - wordSize, wordSize)];
        ++count;
        l += wordSize;
      }
    }

    return output;
  }
};
