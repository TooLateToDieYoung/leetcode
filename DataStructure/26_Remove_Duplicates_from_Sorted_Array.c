
int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    int i, counter = 1, * record = nums;

    for(i=1; i<numsSize; ++i){
        if(nums[i] != *record){
            *(++record) = nums[i];
            ++counter;
        }
    }
    
    return counter;
}