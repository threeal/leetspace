#include <string>
#include <vector>

extern "C" {
char** removeSubfolders(char** folder, int folderSize, int* returnSize);
}

std::vector<std::string> solution_c(std::vector<std::string> folder) {
  std::vector<char*> folderDatas(folder.size());
  for (std::size_t i{0}; i < folder.size(); ++i) {
    folderDatas[i] = folder[i].data();
  }

  int returnSize{};
  char** returnData = removeSubfolders(
      folderDatas.data(), folderDatas.size(), &returnSize);

  std::vector<std::string> output(returnSize);
  for (std::size_t i{0}; i < output.size(); ++i) {
    output[i] = returnData[i];
  }

  return output;
}
