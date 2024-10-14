#include <cstdlib>
#include <string>
#include <vector>

class Solution {
 public:
  std::string nearestPalindromic(std::string n) {
    std::size_t half = n.size() - (n.size() / 2) - 1;

    long long num{0};
    for (std::size_t i{0}; i <= half; ++i) {
      num = num * 10 + n[i] - '0';
    }

    std::vector<long long> polindromes{num, num + 1, num - 1};
    long long ten{n.size() % 2 == 0 ? 1 : 10};
    for (std::size_t i{half + 1}; i < n.size(); ++i) {
      num = num * 10 + n[i] - '0';
      for (auto& polindrome : polindromes) {
        polindrome = polindrome * 10 + (polindrome / ten) % 10;
      }
      ten *= 100;
    }

    if (polindromes.front() % 10 == 1 && n.size() >= 2) {
      long long polindrome{0};
      for (std::size_t i{n.size() - 1}; i > 0; --i) {
        polindrome = polindrome * 10 + 9;
      }
      polindromes.push_back(polindrome);
    } else if (polindromes.front() % 10 == 9) {
      long long polindrome{1};
      for (std::size_t i{n.size()}; i > 0; --i) {
        polindrome *= 10;
      }
      polindromes.push_back(polindrome + 1);
    }

    while (polindromes.front() == num) polindromes.erase(polindromes.begin());

    long long prevDistance = std::abs(polindromes.front() - num);
    for (std::size_t i{polindromes.size() - 1}; i > 0; --i) {
      const long long distance = std::abs(polindromes[i] - num);
      if (distance < prevDistance) {
        polindromes.front() = polindromes[i];
        prevDistance = distance;
      } else if (distance == prevDistance && polindromes[i] < polindromes.front()) {
        polindromes.front() = polindromes[i];
        prevDistance = distance;
      }
    }

    return std::to_string(polindromes.front());
  }
};
