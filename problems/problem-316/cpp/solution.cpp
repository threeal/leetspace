class Solution {
 public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, size_t> counts;
    for (const auto c : s) {
      ++counts[c];
    }

    unordered_set<char> existed;
    stack<char> orders;

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

    string res;
    while (!orders.empty()) {
      res = orders.top() + res;
      orders.pop();
    }

    return res;
  }
};
