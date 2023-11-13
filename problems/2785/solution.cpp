// The solution can be done by counting the number of vowel occurrences and then replacing each vowel using that count as references.

class Solution {
 public:
  string sortVowels(string s) {
    // Initializes a map for storing the count of vowels.
    map<char, int> vowelsCount{
        {'A', 0}, {'E', 0}, {'I', 0}, {'O', 0}, {'U', 0}, {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};

    // Count vowels in a string and store it in the map.
    for (const auto c : s) {
      auto it = vowelsCount.find(c);
      if (it == vowelsCount.end()) continue;
      ++(it->second);
    }

    // Replace vowels in a string with ordered vowels from the map.
    auto it = vowelsCount.begin();
    for (auto& c : s) {
      if (!vowelsCount.contains(c)) continue;
      while (it->second <= 0) ++it;
      c = it->first;
      --(it->second);
    }

    // Return the modified string.
    return s;
  }
};
