#include <string>
#include <vector>

extern "C" {
int findMaxForm(char** strs, int strsSize, int m, int n);
}

int solution_c(std::vector<std::string> strs, int m, int n) {
  std::vector<char*> strsDatas(strs.size());
  for (std::size_t i{0}; i < strs.size(); ++i) {
    strsDatas[i] = strs[i].data();
  }

  return findMaxForm(strsDatas.data(), strs.size(), m, n);
}
