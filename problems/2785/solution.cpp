class Solution {
 public:
  string sortVowels(string s) {
    map<char, int> vowelsCount{
        {'A', 0}, {'E', 0}, {'I', 0}, {'O', 0}, {'U', 0}, {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};

    for (const auto c : s) {
      auto it = vowelsCount.find(c);
      if (it == vowelsCount.end()) continue;
      ++(it->second);
    }

    auto it = vowelsCount.begin();
    for (auto& c : s) {
      if (!vowelsCount.contains(c)) continue;
      while (it->second <= 0) ++it;
      c = it->first;
      --(it->second);
    }

    return s;
  }
};
