#include <string>

class AllOne {
 public:
  AllOne() {}

  void inc(std::string /*key*/) {}

  void dec(std::string /*key*/) {}

  std::string getMaxKey() {
    return "";
  }

  std::string getMinKey() {
    return "";
  }
};
