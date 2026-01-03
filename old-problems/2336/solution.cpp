#include <queue>
#include <unordered_set>

class SmallestInfiniteSet {
 private:
  std::priority_queue<int> addedNums;
  std::unordered_set<int> isNumAdded;
  int maxNum;

 public:
  SmallestInfiniteSet() : addedNums{}, isNumAdded{}, maxNum{1} {}

  int popSmallest() {
    if (addedNums.empty()) return maxNum++;
    const int num{-addedNums.top()};
    addedNums.pop();
    isNumAdded.erase(num);
    return num;
  }

  void addBack(int num) {
    if (num < maxNum) {
      const auto it = isNumAdded.find(num);
      if (it == isNumAdded.end()) {
        addedNums.push(-num);
        isNumAdded.insert(num);
      }
    }
  }
};
