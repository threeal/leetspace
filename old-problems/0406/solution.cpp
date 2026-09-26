#include <algorithm>
#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> reconstructQueue(
      std::vector<std::vector<int>>& people) {
    std::vector<std::vector<int>> output(people.size());

    std::stack<std::size_t> front{}, back{};
    for (std::size_t i{0}; i < people.size(); ++i) front.push(i);

    std::sort(people.begin(), people.end(), [&](const auto& a, const auto& b) {
      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    for (const auto& person : people) {
      const std::size_t n = person[1];
      while (front.size() < n) {
        front.push(back.top());
        back.pop();
      }

      while (front.size() > n) {
        back.push(front.top());
        front.pop();
      }

      output[back.top()] = person;
      back.pop();
    }

    return output;
  }
};
