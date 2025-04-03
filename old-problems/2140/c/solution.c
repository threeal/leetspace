long long mostPoints(
    int** questions, int questionsSize, int* questionsColSize) {
  (void)questionsColSize;

  static long long points[100001];
  points[questionsSize - 1] = questions[questionsSize - 1][0];

  for (int i = questionsSize - 1; i > 0; --i) {
    points[i - 1] = questions[i - 1][0];
    if (i + questions[i - 1][1] < questionsSize) {
      points[i - 1] += points[i + questions[i - 1][1]];
    }
    if (points[i] > points[i - 1]) points[i - 1] = points[i];
  }

  return points[0];
}
