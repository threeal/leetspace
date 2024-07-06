#include <algorithm>
#include <vector>

struct DiagonalIterator {
  using iterator_category = std::random_access_iterator_tag;
  using difference_type = int;
  using value_type = int;
  using pointer = int*;
  using reference = int&;

  std::vector<int>* data;
  int y;
  int x;

  DiagonalIterator() {}
  DiagonalIterator(const DiagonalIterator& it) : data{it.data}, y{it.y}, x{it.x} {}
  DiagonalIterator(std::vector<int>* data, int y, int x) : data{data}, y{y}, x{x} {}

  DiagonalIterator& operator=(const DiagonalIterator& other) {
    data = other.data;
    y = other.y;
    x = other.x;
    return *this;
  }

  DiagonalIterator& operator+=(int diff) {
    y += diff;
    x += diff;
    return *this;
  }

  DiagonalIterator& operator-=(int diff) {
    y -= diff;
    x -= diff;
    return *this;
  }

  int& operator*() const { return data[y][x]; }

  DiagonalIterator& operator++() {
    ++y;
    ++x;
    return *this;
  }

  DiagonalIterator& operator--() {
    --y;
    --x;
    return *this;
  }
};

bool operator==(const DiagonalIterator& lhs, const DiagonalIterator& rhs) {
  return lhs.y == rhs.y;
}

bool operator<(const DiagonalIterator& lhs, const DiagonalIterator& rhs) {
  return lhs.y < rhs.y;
}

bool operator>=(const DiagonalIterator& lhs, const DiagonalIterator& rhs) {
  return lhs.y >= rhs.y;
}

DiagonalIterator operator+(const DiagonalIterator& it, int diff) {
  return DiagonalIterator(it.data, it.y + diff, it.x + diff);
}

DiagonalIterator operator-(const DiagonalIterator& it, int diff) {
  return DiagonalIterator(it.data, it.y - diff, it.x - diff);
}

int operator-(const DiagonalIterator& lhs, const DiagonalIterator& rhs) {
  return lhs.y - rhs.y;
}

class Solution {
 public:
  std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat) {
    const int m = mat.size();
    if (m == 1) return mat;

    const int n = mat.front().size();
    if (n == 1) return mat;

    DiagonalIterator begin(mat.data(), m - 2, 0);
    DiagonalIterator end(mat.data(), m, 2);

    while (begin.y > 0 && end.x < n) {
      std::sort(begin, end);
      --begin.y;
      ++end.x;
    }

    while (begin.y > 0) {
      std::sort(begin, end);
      --begin.y;
      --end.y;
    }

    while (end.x < n) {
      std::sort(begin, end);
      ++begin.x;
      ++end.x;
    }

    while (end.y > 0) {
      std::sort(begin, end);
      ++begin.x;
      --end.y;
    }

    return mat;
  }
};
