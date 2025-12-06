#include <string>
#include <vector>

class CombinationIterator {
 private:
  std::string characters;
  std::vector<std::size_t> indices;
  std::vector<std::size_t> maxIndices;

 public:
  CombinationIterator(std::string characters, int combinationLength)
      : characters{characters},
        indices(combinationLength),
        maxIndices(combinationLength) {
    for (std::size_t i{0}; i < indices.size(); ++i) {
      indices[i] = i;
      maxIndices[i] = characters.size() - (indices.size() - i);
    }
  }

  std::string next() {
    std::string s(indices.size(), 0);
    for (std::size_t i{0}; i < indices.size(); ++i) {
      s[i] = characters[indices[i]];
    }

    std::size_t i{indices.size()};
    while (i > 0 && ++indices[i - 1] > maxIndices[i - 1]) --i;
    if (i > 0) {
      while (i < indices.size()) {
        indices[i] = indices[i - 1] + 1;
        ++i;
      }
    }

    return s;
  }

  bool hasNext() {
    return indices[0] <= maxIndices[0];
  }
};
