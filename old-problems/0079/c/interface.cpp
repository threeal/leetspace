#include <string>
#include <vector>

extern "C" {
bool exist(char** board, int boardSize, int* boardColSize, char* word);
}

bool solution_c(std::vector<std::vector<char>> board, std::string word) {
  std::vector<char*> boardDatas(board.size());
  std::vector<int> boardSizes(board.size());
  for (std::size_t i{0}; i < board.size(); ++i) {
    boardDatas[i] = board[i].data();
    boardSizes[i] = board[i].size();
  }

  return exist(boardDatas.data(), boardDatas.size(), boardSizes.data(), word.data());
}
