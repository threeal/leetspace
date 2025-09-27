#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int minimumTeachings(
      int n, std::vector<std::vector<int>>& languages,
      std::vector<std::vector<int>>& friendships) {
    std::vector<std::unordered_set<int>> languagesSets(languages.size());
    for (std::size_t i{0}; i < languagesSets.size(); ++i) {
      for (const auto& language : languages[i]) {
        languagesSets[i].insert(language);
      }
    }

    std::vector<int> languagesCounts(n, 0);

    int needLearn{0};
    std::vector<bool> visited(languages.size(), false);

    for (const auto& friendship : friendships) {
      bool canCommunicate{false};
      for (const auto language : languagesSets[friendship[0] - 1]) {
        if (languagesSets[friendship[1] - 1].contains(language)) {
          canCommunicate = true;
          break;
        }
      }

      if (!canCommunicate) {
        if (!visited[friendship[0] - 1]) {
          visited[friendship[0] - 1] = true;
          ++needLearn;

          for (const auto language : languagesSets[friendship[0] - 1]) {
            ++languagesCounts[language - 1];
          }
        }

        if (!visited[friendship[1] - 1]) {
          visited[friendship[1] - 1] = true;
          ++needLearn;

          for (const auto language : languagesSets[friendship[1] - 1]) {
            ++languagesCounts[language - 1];
          }
        }
      }
    }

    return needLearn -
        *std::max_element(languagesCounts.begin(), languagesCounts.end());
  }
};
