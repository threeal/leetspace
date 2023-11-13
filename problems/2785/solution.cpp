const set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

class Solution {
 public:
  string sortVowels(string s) {
    map<char, int> vowelsCount;
    for (const auto c : s) {
      if (!vowels.contains(c)) continue;
      ++vowelsCount[c];
    }

    auto it = vowelsCount.begin();
    for (auto& c : s) {
      if (!vowels.contains(c)) continue;
      while (it->second <= 0) ++it;
      c = it->first;
      --(it->second);
    }

    return s;
  }
};
