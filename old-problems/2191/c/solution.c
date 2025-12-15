int* sortJumbled(
    int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize) {
  *returnSize = mappingSize < numsSize ? mappingSize : numsSize;
  return mappingSize < numsSize ? mapping : nums;
}
