#include <cstring>
#include <vector>

extern "C" {
int* maximumBeauty(
    int** items, int itemsSize, int* itemsColSize,
    int* queries, int queriesSize, int* returnSize);
}

std::vector<int> solution_c(
    std::vector<std::vector<int>> items, std::vector<int> queries) {
  std::vector<int*> itemsDatas(items.size());
  std::vector<int> itemsSizes(items.size());
  for (std::size_t i{0}; i < items.size(); ++i) {
    itemsDatas[i] = items[i].data();
    itemsSizes[i] = items[i].size();
  }

  int returnSize{};
  const auto returnData = maximumBeauty(
      itemsDatas.data(), itemsDatas.size(), itemsSizes.data(),
      queries.data(), queries.size(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
