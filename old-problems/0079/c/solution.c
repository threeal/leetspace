#include <stdbool.h>

bool checkExistRecursively(char** board, int boardSize, int* boardColSize, char* word, int y, int x);

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
  for (int y = 0; y < boardSize; ++y) {
    for (int x = 0; x < boardColSize[y]; ++x) {
      if (board[y][x] == *word && checkExistRecursively(board, boardSize, boardColSize, word + 1, y, x)) return true;
    }
  }

  return false;
}

bool checkExistRecursively(char** board, int boardSize, int* boardColSize, char* word, int y, int x) {
  if (*word == 0) return true;

  const char tmp = board[y][x];
  board[y][x] = 0;

  if (y > 0 && board[y - 1][x] == *word && checkExistRecursively(board, boardSize, boardColSize, word + 1, y - 1, x)) return true;
  if (y < boardSize - 1 && board[y + 1][x] == *word && checkExistRecursively(board, boardSize, boardColSize, word + 1, y + 1, x)) return true;
  if (x > 0 && board[y][x - 1] == *word && checkExistRecursively(board, boardSize, boardColSize, word + 1, y, x - 1)) return true;
  if (x < boardColSize[y] - 1 && board[y][x + 1] == *word && checkExistRecursively(board, boardSize, boardColSize, word + 1, y, x + 1)) return true;

  board[y][x] = tmp;
  return false;
}
