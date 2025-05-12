char* interpret(char* command) {
  int l = 0, r = 0;
  while (command[r] != 0) {
    if (command[r] == '(') {
      if (command[r + 1] == ')') {
        command[l++] = 'o';
        r += 2;
      } else {
        command[l++] = 'a';
        command[l++] = 'l';
        r += 4;
      }
    } else {
      command[l++] = 'G';
      ++r;
    }
  }
  command[l] = 0;
  return command;
}
