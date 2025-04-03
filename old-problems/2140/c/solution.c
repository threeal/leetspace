long long mostPoints(
    int** questions, int questionsSize, int* questionsColSize) {
  (void)questionsColSize;
  return questions[questionsSize - 1][1];
}
