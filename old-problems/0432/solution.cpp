#include <string>
#include <unordered_map>

class AllOne {
 private:
  struct KeyNode;

  struct CountNode {
    int count;
    KeyNode* oldestKey;
    KeyNode* newestKey;
    CountNode* prev;
    CountNode* next;

    CountNode(int count)
        : count{count}, oldestKey{nullptr}, newestKey{nullptr}, prev{nullptr}, next{nullptr} {}
  };

  struct KeyNode {
    std::string key;
    CountNode* parentCount;
    KeyNode* prev;
    KeyNode* next;

    KeyNode(const std::string& key)
        : key{key}, parentCount{nullptr}, prev{nullptr}, next{nullptr} {}
  };

  std::unordered_map<std::string, KeyNode*> keysNodes;

  CountNode* minCount;
  CountNode* maxCount;

 public:
  AllOne() : keysNodes{}, minCount{nullptr}, maxCount{nullptr} {}

  ~AllOne() {
    while (minCount != nullptr) {
      const auto next = minCount->next;
      delete minCount;
      minCount = next;
    }

    for (const auto& [key, node] : keysNodes) {
      delete node;
    }
  }

  void inc(std::string key) {
    auto it = keysNodes.find(key);
    if (it == keysNodes.end()) {
      auto keyNode = new KeyNode(key);
      if (minCount == nullptr) {
        minCount = maxCount = new CountNode(1);
      } else if (minCount->count != 1) {
        minCount->prev = new CountNode(1);
        minCount->prev->next = minCount;
        minCount = minCount->prev;
      }

      keyNode->parentCount = minCount;
      if (minCount->newestKey == nullptr) {
        minCount->oldestKey = minCount->newestKey = keyNode;
      } else {
        minCount->newestKey->next = keyNode;
        keyNode->prev = minCount->newestKey;
        minCount->newestKey = keyNode;
      }

      keysNodes.emplace(key, keyNode);
    } else {
      auto keyNode = it->second;
      auto countNode = keyNode->parentCount;

      if (countNode->next == nullptr) {
        countNode->next = new CountNode(countNode->count + 1);
        countNode->next->prev = countNode;
        maxCount = countNode->next;
      } else if (countNode->next->count != countNode->count + 1) {
        const auto next = countNode->next;
        countNode->next = new CountNode(countNode->count + 1);
        countNode->next->next = next;
        next->prev = countNode->next;
        countNode->next->prev = countNode;
      }

      if (keyNode->prev == nullptr) {
        if (keyNode->next == nullptr) {
          countNode->oldestKey = nullptr;
          countNode->newestKey = nullptr;
        } else {
          countNode->oldestKey = keyNode->next;
          countNode->oldestKey->prev = nullptr;
        }
      } else {
        if (keyNode->next == nullptr) {
          countNode->newestKey = keyNode->prev;
          countNode->newestKey->next = nullptr;
        } else {
          keyNode->prev->next = keyNode->next;
          keyNode->next->prev = keyNode->prev;
        }
      }

      keyNode->parentCount = countNode->next;

      if (countNode->next->newestKey == nullptr) {
        countNode->next->oldestKey = countNode->next->newestKey = keyNode;
        keyNode->prev = nullptr;
        keyNode->next = nullptr;
      } else {
        countNode->next->newestKey->next = keyNode;
        keyNode->prev = countNode->next->newestKey;
        keyNode->next = nullptr;
        countNode->next->newestKey = keyNode;
      }

      if (countNode->oldestKey == nullptr) {
        if (countNode->prev == nullptr) {
          if (countNode->next == nullptr) {
            minCount = nullptr;
            maxCount = nullptr;
          } else {
            minCount = countNode->next;
            minCount->prev = nullptr;
          }
        } else {
          if (countNode->next == nullptr) {
            maxCount = countNode->prev;
            maxCount->next = nullptr;
          } else {
            countNode->prev->next = countNode->next;
            countNode->next->prev = countNode->prev;
          }
        }
        delete countNode;
      }
    }
  }

  void dec(std::string key) {
    auto it = keysNodes.find(key);
    if (it == keysNodes.end()) return;

    auto keyNode = it->second;
    auto countNode = keyNode->parentCount;

    if (countNode->count == 1) {
      if (keyNode->prev == nullptr) {
        if (keyNode->next == nullptr) {
          countNode->oldestKey = nullptr;
          countNode->newestKey = nullptr;
        } else {
          countNode->oldestKey = keyNode->next;
          countNode->oldestKey->prev = nullptr;
        }
      } else {
        if (keyNode->next == nullptr) {
          countNode->newestKey = keyNode->prev;
          countNode->newestKey->next = nullptr;
        } else {
          keyNode->prev->next = keyNode->next;
          keyNode->next->prev = keyNode->prev;
        }
      }

      if (countNode->oldestKey == nullptr) {
        if (countNode->next == nullptr) {
          minCount = nullptr;
          maxCount = nullptr;
        } else {
          minCount = countNode->next;
          minCount->prev = nullptr;
        }
        delete countNode;
      }

      keysNodes.erase(it);
      delete keyNode;
    } else {
      if (countNode->prev == nullptr) {
        countNode->prev = new CountNode(countNode->count - 1);
        countNode->prev->next = countNode;
        minCount = countNode->prev;
      } else if (countNode->prev->count != countNode->count - 1) {
        const auto prev = countNode->prev;
        countNode->prev = new CountNode(countNode->count - 1);
        countNode->prev->prev = prev;
        prev->next = countNode->prev;
        countNode->prev->next = countNode;
      }

      if (keyNode->prev == nullptr) {
        if (keyNode->next == nullptr) {
          countNode->oldestKey = nullptr;
          countNode->newestKey = nullptr;
        } else {
          countNode->oldestKey = keyNode->next;
          countNode->oldestKey->prev = nullptr;
        }
      } else {
        if (keyNode->next == nullptr) {
          countNode->newestKey = keyNode->prev;
          countNode->newestKey->next = nullptr;
        } else {
          keyNode->prev->next = keyNode->next;
          keyNode->next->prev = keyNode->prev;
        }
      }

      keyNode->parentCount = countNode->prev;

      if (countNode->prev->newestKey == nullptr) {
        countNode->prev->oldestKey = countNode->prev->newestKey = keyNode;
        keyNode->prev = nullptr;
        keyNode->next = nullptr;
      } else {
        countNode->prev->newestKey->next = keyNode;
        keyNode->prev = countNode->prev->newestKey;
        keyNode->next = nullptr;
        countNode->prev->newestKey = keyNode;
      }

      if (countNode->oldestKey == nullptr) {
        if (countNode->prev == nullptr) {
          if (countNode->next == nullptr) {
            minCount = nullptr;
            maxCount = nullptr;
          } else {
            minCount = countNode->next;
            minCount->prev = nullptr;
          }
        } else {
          if (countNode->next == nullptr) {
            maxCount = countNode->prev;
            maxCount->next = nullptr;
          } else {
            countNode->prev->next = countNode->next;
            countNode->next->prev = countNode->prev;
          }
        }
        delete countNode;
      }
    }
  }

  std::string getMaxKey() {
    return maxCount == nullptr ? "" : maxCount->oldestKey->key;
  }

  std::string getMinKey() {
    return minCount == nullptr ? "" : minCount->oldestKey->key;
  }
};
