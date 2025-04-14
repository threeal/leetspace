#include <string>
#include <unordered_set>

class Solution {
 public:
  long long countGoodIntegers(int n, int k) {
    long long lexp{1};
    for (int i{1}; i < n; ++i) lexp *= 10;

    std::string freqs(10, 0);
    std::unordered_set<std::string> exists{};
    return searchAndCount(lexp, 1, 0, k, freqs, exists);
  }

 private:
  long long searchAndCount(
      long long lexp, long long rexp, long long num, int k,
      std::string& freqs, std::unordered_set<std::string>& exists) {
    long long count{0};
    if (lexp < rexp) {
      if (num % k == 0 && !exists.contains(freqs)) {
        char sum{0};
        for (const auto freq : freqs) sum += freq;

        long long top{1};
        for (char i{2}; i <= sum; ++i) top *= i;

        long long bottom{1};
        for (const auto freq : freqs) {
          for (char i{2}; i <= freq; ++i) bottom *= i;
        }

        count += top / bottom;
        if (freqs[0] > 0) count -= (top / sum) / (bottom / freqs[0]);

        exists.insert(freqs);
      }
    } else {
      if (lexp == rexp) {
        if (rexp > 1) {
          ++freqs[0];
          count += searchAndCount(lexp / 10, rexp * 10, num, k, freqs, exists);
          --freqs[0];
        }
        for (int i{1}; i <= 9; ++i) {
          ++freqs[i];
          num += lexp;
          count += searchAndCount(lexp / 10, rexp * 10, num, k, freqs, exists);
          --freqs[i];
        }
      } else {
        if (rexp > 1) {
          freqs[0] += 2;
          count += searchAndCount(lexp / 10, rexp * 10, num, k, freqs, exists);
          freqs[0] -= 2;
        }
        for (int i{1}; i <= 9; ++i) {
          freqs[i] += 2;
          num += lexp + rexp;
          count += searchAndCount(lexp / 10, rexp * 10, num, k, freqs, exists);
          freqs[i] -= 2;
        }
      }
    }
    return count;
  }
};
