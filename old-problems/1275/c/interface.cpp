#include <string>
#include <vector>

extern "C" {
char* tictactoe(int** moves, int movesSize, int* movesColSize);
}

std::string solution_c(std::vector<std::vector<int>> moves) {
  std::vector<int*> movesDatas(moves.size());
  std::vector<int> movesColSize(moves.size());
  for (std::size_t i = 0; i < moves.size(); ++i) {
    movesDatas[i] = moves[i].data();
    movesColSize[i] = moves[i].size();
  }

  return tictactoe(movesDatas.data(), movesDatas.size(), movesColSize.data());
}
