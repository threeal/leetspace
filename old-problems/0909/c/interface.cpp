#include <vector>

extern "C" {
int snakesAndLadders(int** board, int boardSize, int* boardColSize);
}

int solution_c(std::vector<std::vector<int>> board) {
  std::vector<int*> boardDatas(board.size());
  std::vector<int> boardSizes(board.size());
  for (int i = board.size() - 1; i >= 0; --i) {
    boardDatas[i] = board[i].data();
    boardSizes[i] = board[i].size();
  }

  return snakesAndLadders(
      boardDatas.data(), boardDatas.size(), boardSizes.data());
}
