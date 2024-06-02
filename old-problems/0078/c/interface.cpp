#include<cstring>
#include<vector>

extern "C"{
int** subsets (int* nums,int numSize, int* returnSize, int** returnColumnSizes);
}

std::vector<std::vector<int>> solution_c(std::vector<int> nums, int numSize){
  std::vector<int*> numsDatas(nums.size());
  std::vector<int> numsSizes(nums.size());
  for(std::size_t i{0}; i<grid.size(); ++i){
    numsDatas[i] = nums[i].data();
    numsSizes[i] = nums[i].size();
  }
  
  int returnSize{};
  const int* returnData{subsets(numsDatas.data() ,numsDatas.size(), &returnSize, numsSize.data())};
  
  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
