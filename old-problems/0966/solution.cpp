#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> spellchecker(
      std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
    return wordlist.empty() ? wordlist : queries;
  }
};
