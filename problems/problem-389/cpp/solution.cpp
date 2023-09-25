class Solution {
 public:
  char findTheDifference(string s, string t) {
    char maps[26];
    for (int i = 0; i < 26; ++i) {
      maps[i] = 0;
    }

    auto it = s.begin();
    auto end = s.end();
    while (it != end) {
      ++maps[*it - 'a'];
      ++it;
    }

    it = t.begin();
    end = t.end();
    while (it != end) {
      --maps[*it - 'a'];
      ++it;
    }

    for (int i = 0; i < 26; ++i) {
      if (maps[i] != 0) return 'a' + i;
    }

    return 'a';
  }
};
