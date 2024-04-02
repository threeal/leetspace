#include <string>
#include <vector>

extern "C" {
int evalRPN(char** tokens, int tokensSize);
}

int solution_c(std::vector<std::string> tokens) {
  std::vector<char*> tokensData(tokens.size());
  for (std::size_t i = 0; i < tokens.size(); ++i) {
    tokensData[i] = tokens[i].data();
  }

  return evalRPN(tokensData.data(), tokensData.size());
}
