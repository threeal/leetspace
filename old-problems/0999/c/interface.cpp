#include <vector>

extern "C" {
int numRookCaptures(char** board, int boardSize, int* boardColSize);
}

int solution_c(std::vector<std::vector<char>> board) {
  std::vector<char*> boardDatas(board.size());
  std::vector<int> boardSizes(board.size());
  for (std::size_t i = 0; i < board.size(); ++i) {
    boardDatas[i] = board[i].data();
    boardSizes[i] = board[i].size();
  }

  return numRookCaptures(boardDatas.data(), board.size(), boardSizes.data());
}
