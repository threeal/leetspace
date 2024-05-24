#include <string>
#include <vector>

class Solution {
 public:
  int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
    std::vector<std::vector<std::int8_t>> wordsCount(words.size(), std::vector<std::int8_t>(26, 0));
    for (int i = words.size() - 1; i >= 0; --i) {
      for (const auto letter : words[i]) {
        ++wordsCount[i][letter - 'a'];
      }
    }

    std::vector<std::int8_t> lettersCount(26, 0);
    for (const auto letter : letters) {
      ++lettersCount[letter - 'a'];
    }

    return maxScoreWords(wordsCount, 0, lettersCount.data(), score.data());
  }

  int maxScoreWords(
      const std::vector<std::vector<std::int8_t>>& wordsCount,
      std::size_t index,
      std::int8_t* lettersCount,
      const int* score) {
    if (index >= wordsCount.size()) return 0;

    int notPick{maxScoreWords(wordsCount, index + 1, lettersCount, score)};

    for (int i{25}; i >= 0; --i) {
      if (wordsCount[index][i] > lettersCount[i]) return notPick;
    }

    int pick{0};
    for (int i{25}; i >= 0; --i) {
      pick += score[i] * wordsCount[index][i];
      lettersCount[i] -= wordsCount[index][i];
    }

    pick += maxScoreWords(wordsCount, index + 1, lettersCount, score);

    for (int i{25}; i >= 0; --i) lettersCount[i] += wordsCount[index][i];

    return notPick > pick ? notPick : pick;
  }
};
