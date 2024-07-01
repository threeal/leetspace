#include <string>
#include <vector>

extern "C" {
bool placeWordInCrossword(
    char** board, int boardSize, int* boardColSize, char* word);
}

bool solution_c(std::vector<std::vector<char>> board, std::string word) {
  std::vector<char*> boardDatas(board.size());
  std::vector<int> boardSizes(board.size());
  for (int i = board.size() - 1; i >= 0; --i) {
    boardDatas[i] = board[i].data();
    boardSizes[i] = board[i].size();
  }

  return placeWordInCrossword(
      boardDatas.data(), boardDatas.size(), boardSizes.data(), word.data());
}
