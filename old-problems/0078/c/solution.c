#include<stdlib.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 1 << numsSize;
    int** result = (int**)malloc(*returnSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        int subsetSize = 0;
        int temp = i;
        while (temp > 0) {
            subsetSize += temp & 1;
            temp >>= 1;
        }
        result[i] = (int*)malloc(subsetSize * sizeof(int));
        (*returnColumnSizes)[i] = subsetSize;
        int index = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i & (1 << j)) {
                result[i][index++] = nums[j];
            }
        }
    }
    return result;
}
