#include <string>
#include <vector>

extern "C" {
int countSeniors(char** details, int detailsSize);
}

int solution_c(std::vector<std::string> details) {
  std::vector<char*> detailsDatas(details.size());
  for (int i = details.size() - 1; i >= 0; --i) {
    detailsDatas[i] = details[i].data();
  }

  return countSeniors(detailsDatas.data(), detailsDatas.size());
}
