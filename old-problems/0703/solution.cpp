#include <queue>
#include <vector>

class KthLargest {
  int k;
  std::priority_queue<int, std::vector<int>, std::greater<int>> q;

 public:
  KthLargest(int k, std::vector<int>& nums) : k{k} {
    for (const auto num : nums) {
      q.push(num);
      if (q.size() > static_cast<std::size_t>(k)) q.pop();
    }
  }

  int add(int val) {
    q.push(val);
    if (q.size() > static_cast<std::size_t>(k)) q.pop();
    return q.top();
  }
};
