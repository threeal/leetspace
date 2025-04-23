#include <vector>

extern "C" {
int numRabbits(int* answers, int answersSize);
}

int solution_c(std::vector<int> answers) {
  return numRabbits(answers.data(), answers.size());
}
