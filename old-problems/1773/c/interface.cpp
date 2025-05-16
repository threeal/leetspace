#include <string>
#include <vector>

extern "C" {
int countMatches(
    char*** items, int itemsSize, int* itemsColSize,
    char* ruleKey, char* ruleValue);
}

int solution_c(
    std::vector<std::vector<std::string>> items,
    std::string ruleKey, std::string ruleValue) {
  std::vector<std::vector<char*>> rawItems(items.size());

  for (std::size_t i{0}; i < items.size(); ++i) {
    rawItems[i].resize(items[i].size());
    for (std::size_t j{0}; j < items[i].size(); ++j) {
      rawItems[i][j] = items[i][j].data();
    }
  }

  std::vector<char**> rawItemsDatas(rawItems.size());
  std::vector<int> rawItemsSizes(rawItems.size());
  for (std::size_t i{0}; i < rawItems.size(); ++i) {
    rawItemsDatas[i] = rawItems[i].data();
    rawItemsSizes[i] = rawItems[i].size();
  }

  return countMatches(
      rawItemsDatas.data(), rawItems.size(), rawItemsSizes.data(),
      ruleKey.data(), ruleValue.data());
}
