#include <cstring>
#include <vector>

class Solution {
 public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    std::vector<int> temp(nums.size());
    mergeSort(temp.data(), nums.data(), nums.data() + nums.size() - 1);
    return nums;
  }

  void mergeSort(int* temp, int* low, int* high) {
    if (low >= high) return;

    int* mid{low + (high - low) / 2};

    mergeSort(temp, low, mid);
    mergeSort(temp, mid + 1, high);

    std::memcpy(temp, low, (high - low + 1) * sizeof(int));
    int* tempMid{temp + (mid - low)};
    int* tempHigh{temp + (high - low)};

    int* outIt{low};

    int* loIt{temp};
    int* hiIt{tempMid + 1};

    while (loIt <= tempMid && hiIt <= tempHigh) {
      if (*loIt <= *hiIt) {
        *outIt = *loIt;
        ++loIt;
      } else {
        *outIt = *hiIt;
        ++hiIt;
      }
      ++outIt;
    }

    if (loIt <= tempMid) {
      std::memcpy(outIt, loIt, (tempMid - loIt + 1) * sizeof(int));
    } else if (hiIt <= tempHigh) {
      std::memcpy(outIt, hiIt, (tempHigh - hiIt + 1) * sizeof(int));
    }
  }
};
