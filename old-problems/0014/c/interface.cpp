#include <string>
#include <vector>

extern "C" {
char* longestCommonPrefix(char** strs, int strsSize);
}

std::string solution_c(std::vector<std::string> strs) {
  std::vector<char*> strsDatas(strs.size());
  for (std::size_t i{0}; i < strs.size(); ++i) {
    strsDatas[i] = strs[i].data();
  }
  return longestCommonPrefix(strsDatas.data(), strsDatas.size());
}
