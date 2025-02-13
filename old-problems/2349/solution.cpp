#include <set>
#include <unordered_map>

class NumberContainers {
 private:
  std::unordered_map<int, int> indexNumbers;
  std::unordered_map<int, std::set<int>> numberIndexes;

 public:
  NumberContainers() : indexNumbers{}, numberIndexes{} {}

  void change(int index, int number) {
    auto in = indexNumbers.find(index);
    if (in != indexNumbers.end()) {
      if (in->second == number) return;
      auto ni = numberIndexes.find(in->second);
      ni->second.erase(in->first);
      if (ni->second.empty()) numberIndexes.erase(ni);
      in->second = number;
    } else {
      indexNumbers.emplace(index, number);
    }
    numberIndexes[number].insert(index);
  }

  int find(int number) {
    auto ni = numberIndexes.find(number);
    if (ni == numberIndexes.end() || ni->second.empty()) return -1;
    return *(ni->second.begin());
  }
};
