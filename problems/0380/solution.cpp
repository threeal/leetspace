#include <unordered_map>

class RandomizedSet {
 private:
  std::unordered_map<int, std::size_t> valuesPositions;
  std::vector<int> values;
  std::size_t lastPosition;

 public:
  RandomizedSet() : lastPosition(0) {}

  bool insert(int val) {
    const auto it = valuesPositions.find(val);
    if (it != valuesPositions.end()) {
      return false;
    }
    valuesPositions.emplace(val, lastPosition);
    if (lastPosition >= values.size()) {
      values.push_back(val);
    } else {
      values[lastPosition] = val;
    }
    ++lastPosition;
    return true;
  }

  bool remove(int val) {
    const auto it = valuesPositions.find(val);
    if (it == valuesPositions.end()) {
      return false;
    }
    --lastPosition;
    values[it->second] = values[lastPosition];
    valuesPositions[values[it->second]] = it->second;
    valuesPositions.erase(it);
    return true;
  }

  int getRandom() {
    return values[std::rand() % lastPosition];
  }
};
