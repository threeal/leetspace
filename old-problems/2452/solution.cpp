#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> twoEditWords(
      std::vector<std::string>& queries,
      std::vector<std::string>& dictionary) {
    return queries.size() < dictionary.size() ? queries : dictionary;
  }
};
