int* diffWaysToCompute(char* expression, int* returnSize) {
  int operands[10];
  int operandsSize = 0;

  char operators[9];
  int operatorsSize = 0;

  int num = 0;
  while (*expression != 0) {
    if (*expression >= '0') {
      num = num * 10 + *expression - '0';
    } else {
      operands[operandsSize++] = num;
      operators[operatorsSize++] = *expression;
      num = 0;
    }
    ++expression;
  }
  operands[operandsSize++] = num;

  // std::vector<std::vector<std::vector<int>>> results(operands.size());
  // for (std::size_t i{0}; i < results.size(); ++i) {
  //   results[i].resize(results.size() - i);
  // }

  // for (std::size_t i{0}; i < operands.size(); ++i) {
  //   results[0][i].push_back(operands[i]);
  // }

  // for (int n = 1; n < results.size(); ++n) {
  //   for (int i = 0; i < results[n].size(); ++i) {
  //     for (std::size_t j{0}; j < n; ++j) {
  //       for (const auto left : results[j][i]) {
  //         for (const auto right : results[n - j - 1][i + j + 1]) {
  //           int result{};
  //           switch (operators[i + j]) {
  //             case '+':
  //               result = left + right;
  //               break;
  //             case '-':
  //               result = left - right;
  //               break;
  //             case '*':
  //               result = left * right;
  //               break;
  //           }
  //           results[n][i].push_back(result);
  //         }
  //       }
  //     }
  //   }
  // }

  *returnSize = 0;
  return 0;
}
