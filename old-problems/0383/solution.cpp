#include <string>

class Solution {
 public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    return ransomNote == magazine;
  }
};
