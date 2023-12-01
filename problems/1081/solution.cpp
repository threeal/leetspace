#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
 public:
  std::string smallestSubsequence(std::string s) {
    std::unordered_map<char, size_t> counts;
    for (const auto c : s) {
      ++counts[c];
    }

    std::unordered_set<char> existed;
    std::stack<char> orders;

    for (const auto c : s) {
      --counts[c];
      if (existed.find(c) != existed.end()) continue;

      while (!orders.empty() && orders.top() > c && counts[orders.top()] > 0) {
        existed.erase(orders.top());
        orders.pop();
      }

      orders.push(c);
      existed.insert(c);
    }

    std::string res;
    while (!orders.empty()) {
      res = orders.top() + res;
      orders.pop();
    }

    return res;
  }
};
