#include <cstring>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combine(int n, int k) {
    int size{1};
    for (int i{1}; i <= k; ++i) {
      size *= n - k + i;
      size /= i;
    }

    std::vector<std::vector<int>> output(size, std::vector<int>(k));
    std::vector<std::vector<int>>::iterator it{output.begin()};
    std::vector<int> arr(k);
    fill(it, arr, 0, 1, n);

    return output;
  }

 private:
  static void fill(
      std::vector<std::vector<int>>::iterator& it,
      std::vector<int>& arr, std::size_t i, int start, int n) {
    const int end = n - (arr.size() - i - 1);
    if (i + 1 == arr.size()) {
      for (int j{start}; j <= end; ++j) {
        arr[i] = j;
        std::memcpy(it->data(), arr.data(), arr.size() * sizeof(int));
        ++it;
      }
    } else {
      for (int j{start}; j <= end; ++j) {
        arr[i] = j;
        fill(it, arr, i + 1, j + 1, n);
      }
    }
  }
};
