#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<std::string> spellchecker(
      std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
    std::unordered_set<std::string_view> exactMatches{};
    std::unordered_map<std::string, std::string_view> capitalMatches{};
    std::unordered_map<std::string, std::string_view> vowelMatches{};

    for (const std::string& word : wordlist) {
      exactMatches.insert(word);

      std::string query{word};
      for (char& c : query) {
        if (c < 'a') c += 'a' - 'A';
      }

      if (!capitalMatches.contains(query)) {
        capitalMatches.emplace(query, word);
      }

      for (char& c : query) {
        switch (c) {
          case 'e':
          case 'i':
          case 'o':
          case 'u':
            c = 'a';
        }
      }

      if (!vowelMatches.contains(query)) {
        vowelMatches.emplace(query, word);
      }
    }

    for (std::string& query : queries) {
      if (exactMatches.contains(query)) continue;

      for (char& c : query) {
        if (c < 'a') c += 'a' - 'A';
      }

      const auto capitalMatch = capitalMatches.find(query);
      if (capitalMatch != capitalMatches.end()) {
        query = capitalMatch->second;
        continue;
      }

      for (char& c : query) {
        switch (c) {
          case 'e':
          case 'i':
          case 'o':
          case 'u':
            c = 'a';
        }
      }

      const auto vowelMatch = vowelMatches.find(query);
      if (vowelMatch != vowelMatches.end()) {
        query = vowelMatch->second;
        continue;
      }

      query = "";
    }

    return queries;
  }
};
