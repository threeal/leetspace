#include<cstring>
#include<vector>
#include<cstdlib>

extern "C"{
int** subsets (int* nums,int numSize, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<int> nums, int numSize){

  int returnSize;
  int* returnColumnSizes;
  const auto returnData = subsets(nums.data() ,nums.size(), &returnSize, &returnColumnSizes);
  
   std::vector<std::vector<int>> output(returnSize);
   std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
