#include <stdbool.h>
#include <string.h>

bool placeWordInCrossword(
    char** board, int boardSize, int* boardColSize, char* word) {
  int wordSize = strlen(word);

  for (int y = boardSize - 1; y >= 0; --y) {
    int x = boardColSize[0] - 1;
    while (x >= 0) {
      while (x >= 0 && board[y][x] == '#') --x;

      if (x < wordSize - 1) break;

      int i = wordSize - 1;
      while (i >= 0) {
        if (board[y][x - i] != ' ' && board[y][x - i] != word[i]) break;
        --i;
      }
      if (i < 0) {
        if (x - wordSize + 1 == 0) return true;
        if (board[y][x - wordSize] == '#') return true;
      }

      i = wordSize - 1;
      while (i >= 0) {
        if (board[y][x - i] != ' ' &&
            board[y][x - i] != word[wordSize - 1 - i]) break;
        --i;
      }
      if (i < 0) {
        if (x - wordSize + 1 == 0) return true;
        if (board[y][x - wordSize] == '#') return true;
      }

      while (x >= 0 && board[y][x] != '#') --x;
    }
  }

  for (int x = boardColSize[0] - 1; x >= 0; --x) {
    int y = boardSize - 1;
    while (y >= 0) {
      while (y >= 0 && board[y][x] == '#') --y;

      if (y < wordSize - 1) break;

      int i = wordSize - 1;
      while (i >= 0) {
        if (board[y - i][x] != ' ' && board[y - i][x] != word[i]) break;
        --i;
      }
      if (i < 0) {
        if (y - wordSize + 1 == 0) return true;
        if (board[y - wordSize][x] == '#') return true;
      }

      i = wordSize - 1;
      while (i >= 0) {
        if (board[y - i][x] != ' ' &&
            board[y - i][x] != word[wordSize - 1 - i]) break;
        --i;
      }
      if (i < 0) {
        if (y - wordSize + 1 == 0) return true;
        if (board[y - wordSize][x] == '#') return true;
      }

      while (y >= 0 && board[y][x] != '#') --y;
    }
  }

  return false;
}
