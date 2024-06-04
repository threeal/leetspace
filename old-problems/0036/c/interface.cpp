#include <vector>

extern "C" {
bool isValidSudoku(char** board, int boardSize, int* boardColSize);
}

bool solution_c(std::vector<std::vector<char>> board) {
  std::vector<char*> boardDatas(board.size());
  std::vector<int> boardSizes(board.size());
  for (std::size_t i = 0; i < board.size(); ++i) {
    boardDatas[i] = board[i].data();
    boardSizes[i] = board[i].size();
  }

  return isValidSudoku(boardDatas.data(), boardDatas.size(), boardSizes.data());
}
