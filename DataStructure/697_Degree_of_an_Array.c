
/* First Trying Runtime = 52ms */
int findShortestSubArray(int* nums, int numsSize){
    int cases = 1;
    for(int i=0; i<numsSize; ++i)
        if(nums[i] >= cases) cases = nums[i] + 1;
    
    int * arr = (int*)calloc(cases, sizeof(int));
    
    for(int i=0; i<numsSize; ++i)
        ++arr[nums[i]];
    
    int maxTimes = 1;
    for(int i=0; i<cases; ++i)
        if(arr[i] > maxTimes) maxTimes = arr[i];
    
    int times, target, counter, result = 0;
    bool enable = false;
    for(int i=0; i<cases; ++i){
        if(arr[i] == maxTimes){
            target = i;
            enable = false;
            counter = 0;
            times = maxTimes;
            
            for(int j=0; times && j<numsSize; ++j){
                if(nums[j] == target){
                    enable = true;
                    --times;
                }
                if(enable) ++counter;
            }
            
            if(!result || counter < result)
                result = counter;
            
        }
    }
    
    free(arr);
    
    return result;
}