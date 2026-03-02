#include <queue>
#include <tuple>
#include <vector>

class Solution {
 public:
  int minimumPairRemoval(std::vector<int>& nums) {
    int invertedCount{0};
    std::vector<bool> isInverted(nums.size() - 1, false);
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] < nums[i - 1]) {
        isInverted[i - 1] = true;
        ++invertedCount;
      }
    }

    if (invertedCount == 0) return 0;

    std::vector<long long> llnums(nums.size());
    for (std::size_t i{0}; i < nums.size(); ++i) llnums[i] = nums[i];

    std::vector<bool> isRemoved(llnums.size(), false);
    std::vector<std::size_t> lefts(llnums.size()), rights(llnums.size());

    std::priority_queue<
        std::tuple<long long, std::size_t, std::size_t>,
        std::vector<std::tuple<long long, std::size_t, std::size_t>>,
        std::greater<>>
        minPairs{};

    lefts[0] = llnums.size();
    rights[0] = 1;

    for (std::size_t i{1}; i < llnums.size(); ++i) {
      lefts[i] = i - 1;
      rights[i] = i + 1;
      minPairs.push({llnums[i - 1] + llnums[i], i - 1, i});
    }

    int removal{0};
    while (invertedCount > 0) {
      ++removal;

      while (true) {
        const auto [sum, i, j] = minPairs.top();
        if (isRemoved[i] || isRemoved[j] || llnums[i] + llnums[j] != sum) {
          minPairs.pop();
        } else {
          break;
        }
      }

      const auto [sum, i, j] = minPairs.top();

      llnums[i] += llnums[j];
      isRemoved[j] = true;

      if (isInverted[i]) {
        isInverted[i] = false;
        --invertedCount;
      }

      if (isInverted[j]) {
        --invertedCount;
      }

      const std::size_t l{findNext(lefts, isRemoved, i)};
      if (l < llnums.size()) {
        rights[l] = i;
        minPairs.push({llnums[l] + llnums[i], l, i});
        if (llnums[i] >= llnums[l]) {
          if (isInverted[l]) {
            isInverted[l] = false;
            --invertedCount;
          }
        } else {
          if (!isInverted[l]) {
            isInverted[l] = true;
            ++invertedCount;
          }
        }
      }

      std::size_t r{findNext(rights, isRemoved, j)};
      if (r < llnums.size()) {
        lefts[r] = i;
        minPairs.push({llnums[i] + llnums[r], i, r});
        if (llnums[r] < llnums[i]) {
          isInverted[i] = true;
          ++invertedCount;
        }
      }
    }

    return removal;
  }

 private:
  static std::size_t findNext(
      std::vector<std::size_t>& nexts, const std::vector<bool>& isRemoved,
      std::size_t i) {
    return nexts[i] < isRemoved.size() && isRemoved[nexts[i]]
        ? (nexts[i] = findNext(nexts, isRemoved, nexts[i]))
        : nexts[i];
  }
};
