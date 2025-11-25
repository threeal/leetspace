#include <string>
#include <vector>

extern "C" {
int maximumValue(char** strs, int strsSize);
}

int solution_c(std::vector<std::string> strs) {
  std::vector<char*> strsDatas(strs.size());
  for (std::size_t i{0}; i < strs.size(); ++i) {
    strsDatas[i] = strs[i].data();
  }

  return maximumValue(strsDatas.data(), strs.size());
}
