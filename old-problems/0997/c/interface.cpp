#include <vector>

extern "C" {
int findJudge(int n, int** trust, int trustSize, int* trustColSize);
}

int solution_c(int n, std::vector<std::vector<int>> trust) {
  std::vector<int*> trustDatas(trust.size());
  std::vector<int> trustColSizes(trust.size());
  for (std::size_t i = 0; i < trust.size(); ++i) {
    trustDatas[i] = trust[i].data();
    trustColSizes[i] = trust[i].size();
  }

  return findJudge(n, trustDatas.data(), trustDatas.size(), trustColSizes.data());
}
