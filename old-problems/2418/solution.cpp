#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> sortPeople(
      std::vector<std::string>& names, std::vector<int>& heights) {
    quickSort(names.data(), heights.data(), 0, names.size() - 1);
    return names;
  }

  // This function implements quick sort to sort the given range of arrays.
  // See: https://www.geeksforgeeks.org/quick-sort/
  void quickSort(
      std::string* names, int* heights, int low, int high) {
    if (low >= high) return;

    int pivot = low - 1;
    for (int i = low; i < high; ++i) {
      if (heights[i] <= heights[high]) continue;
      ++pivot;
      std::swap(names[pivot], names[i]);
      std::swap(heights[pivot], heights[i]);
    }

    ++pivot;
    std::swap(names[pivot], names[high]);
    std::swap(heights[pivot], heights[high]);

    quickSort(names, heights, low, pivot - 1);
    quickSort(names, heights, pivot + 1, high);
  }
};
