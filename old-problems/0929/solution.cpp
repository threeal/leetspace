#include <cstring>
#include <string>
#include <vector>

class Solution {
 public:
  int numUniqueEmails(std::vector<std::string>& emails) {
    int uniques{0};

    std::vector<bool> checked(emails.size());
    for (int i = emails.size() - 1; i >= 0; --i) {
      if (checked[i]) continue;

      ++uniques;
      for (int j = i - 1; j >= 0; --j) {
        if (checked[j]) continue;
        if (compareEmail(emails[i].c_str(), emails[j].c_str()))
          checked[j] = true;
      }
    }

    return uniques;
  }

  bool compareEmail(const char* a, const char* b) {
    while (*a != '@' && *b != '@' && *a == *b) {
      while (*(++a) == '.') continue;
      if (*a == '+') {
        while (*a != '@') ++a;
      }

      while (*(++b) == '.') continue;
      if (*b == '+') {
        while (*b != '@') ++b;
      }
    }

    return (*a == '@' && *b == '@')
        ? std::strcmp(a, b) == 0
        : false;
  }
};
