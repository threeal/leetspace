int longestValidParentheses(char* s) {
  int stack[30001];

  int stackTop = 0;
  stack[stackTop] = -1;

  int longest = 0;
  for (int i = 0; s[i] != 0; ++i) {
    if (s[i] == '(') {
      stack[++stackTop] = i;
    } else {
      --stackTop;
      if (stackTop < 0) {
        stack[++stackTop] = i;
      } else if (i - stack[stackTop] > longest) {
        longest = i - stack[stackTop];
      }
    }
  }

  return longest;
}
