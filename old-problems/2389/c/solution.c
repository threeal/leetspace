int* answerQueries(
    int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
  *returnSize = numsSize >= queriesSize ? numsSize : queriesSize;
  return numsSize >= queriesSize ? nums : queries;
}
