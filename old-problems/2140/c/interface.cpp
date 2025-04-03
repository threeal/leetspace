#include <vector>

extern "C" {
long long mostPoints(
    int** questions, int questionsSize, int* questionsColSize);
}

long long solution_c(std::vector<std::vector<int>> questions) {
  std::vector<int*> questionsDatas(questions.size());
  std::vector<int> questionsSizes(questions.size());
  for (std::size_t i{0}; i < questions.size(); ++i) {
    questionsDatas[i] = questions[i].data();
    questionsSizes[i] = questions[i].size();
  }

  return mostPoints(
      questionsDatas.data(), questions.size(), questionsSizes.data());
}
