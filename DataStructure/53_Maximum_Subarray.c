#define MAX(x,y) ((x)>(y)?(x):(y))

int maxSubArray(int* nums, int numsSize){
    int i, currsum = *nums, bestsum = *nums;
    for(i=1; i<numsSize; ++i){
        currsum = MAX(currsum + nums[i], nums[i]);
        bestsum = MAX(bestsum, currsum);
    }
    return bestsum;
}