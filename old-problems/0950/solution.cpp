#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
    std::sort(deck.begin(), deck.end());
    return reorder(deck, 0);
  }

 private:
  static std::vector<int> reorder(const std::vector<int>& deck, std::size_t l) {
    if (l == deck.size() - 1) return {deck.back()};

    const std::size_t n{deck.size() - l};
    const std::size_t mid{n / 2 + n % 2};

    std::vector<int> output(n);
    for (std::size_t i{0}; i < mid; ++i) {
      output[i * 2] = deck[l + i];
    }

    const std::vector<int> rDeck{reorder(deck, l + mid)};
    if (rDeck.size() == mid) {
      for (std::size_t i{0}; i < rDeck.size(); ++i) {
        output[i * 2 + 1] = rDeck[i];
      }
    } else {
      output[1] = rDeck.back();
      for (std::size_t i{1}; i < rDeck.size(); ++i) {
        output[i * 2 + 1] = rDeck[i - 1];
      }
    }

    return output;
  }
};
