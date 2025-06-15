int finalPositionOfSnake(int n, char** commands, int commandsSize) {
  return n + *commands[commandsSize - 1];
}
