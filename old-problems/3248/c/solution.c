int finalPositionOfSnake(int n, char** commands, int commandsSize) {
  int position = 0;
  for (int i = 0; i < commandsSize; ++i) {
    switch (commands[i][0]) {
      case 'U':
        position -= n;
        break;

      case 'R':
        ++position;
        break;

      case 'D':
        position += n;
        break;

      case 'L':
        --position;
        break;
    }
  }
  return position;
}
