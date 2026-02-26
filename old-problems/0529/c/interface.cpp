#include <cstring>
#include <vector>

extern "C" {
char** updateBoard(
    char** board, int boardSize, int* boardColSize,
    int* click, int clickSize, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<char>> solution_c(
    std::vector<std::vector<char>> board, std::vector<int> click) {
  std::vector<char*> boardDatas(board.size());
  std::vector<int> boardSizes(board.size());
  for (std::size_t i{0}; i < board.size(); ++i) {
    boardDatas[i] = board[i].data();
    boardSizes[i] = board[i].size();
  }

  int returnSize{};
  int* returnColumnSizes{};
  char** returnData{
      updateBoard(
          boardDatas.data(), board.size(), boardSizes.data(),
          click.data(), click.size(), &returnSize, &returnColumnSizes)};

  std::vector<std::vector<char>> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i].resize(returnColumnSizes[i]);
    std::memcpy(
        output[i].data(), returnData[i], returnColumnSizes[i] * sizeof(char));
  }

  return output;
}
