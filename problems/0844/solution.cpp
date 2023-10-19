class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    auto ss = s.rbegin();
    auto tt = t.rbegin();

    const auto se = s.rend();
    const auto te = t.rend();

    // Iterating through each string backwards.
    while (true) {
      // Shift both iterators to skip the backspace character.
      shift_backspace(ss, se);
      shift_backspace(tt, te);

      if (ss == se || tt == te) break;

      // Both strings are unequal if these iterators contain different characters.
      if (*ss != *tt) return false;

      ++ss;
      ++tt;
    }

    // Both strings are equal if both iterators have reached the end.
    return ss == se && tt == te;
  }

  // This function will increment the iterator as long as it still contains the backspace character (`#`).
  void shift_backspace(string::reverse_iterator& it, string::reverse_iterator end) {
    int skip = 0;
    while (it != end && *it == '#') {
      ++skip;
      ++it;

      while (skip > 0 && it != end && *it != '#') {
        --skip;
        ++it;
      }
    }
  }
};
