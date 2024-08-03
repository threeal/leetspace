#include <vector>

extern "C" {
int minHeightShelves(
    int** books, int booksSize, int* booksColSize, int shelfWidth);
}

int solution_c(std::vector<std::vector<int>> books, int shelfWidth) {
  std::vector<int*> booksDatas(books.size());
  std::vector<int> booksSizes(books.size());
  for (int i = books.size() - 1; i >= 0; --i) {
    booksDatas[i] = books[i].data();
    booksSizes[i] = books[i].size();
  }

  return minHeightShelves(
      booksDatas.data(), booksDatas.size(), booksSizes.data(), shelfWidth);
}
