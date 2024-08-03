#include <vector>

class Solution {
 public:
  int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {
    std::vector<int> minHeights(books.size() + 1);
    minHeights[books.size()] = 0;

    for (int i = books.size() - 1; i >= 0; --i) {
      int width{books[i][0]};
      int height{books[i][1]};

      minHeights[i] = height + minHeights[i + 1];
      for (std::size_t j = i + 1; j < books.size(); ++j) {
        width += books[j][0];
        if (width > shelfWidth) break;
        if (books[j][1] > height) height = books[j][1];
        if (height + minHeights[j + 1] < minHeights[i]) {
          minHeights[i] = height + minHeights[j + 1];
        }
      }
    }

    return minHeights[0];
  }
};
