/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int * pRet = (int *)malloc(sizeof(int) * 2);
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                pRet[0] = i;
                pRet[1] = j;
                break;
            }
        }
    }
    
    return pRet;
}