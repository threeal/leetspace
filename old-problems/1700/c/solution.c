int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
  int preferCircular = 0;
  int preferSquare = 0;
  for (int i = 0; i < studentsSize; ++i) {
    students[i] == 0 ? ++preferCircular : ++preferSquare;
  }

  for (int i = 0; i < sandwichesSize; ++i) {
    if (sandwiches[i] == 0) {
      if (--preferCircular < 0) return preferSquare;
    } else {
      if (--preferSquare < 0) return preferCircular;
    }
  }

  return 0;
}
