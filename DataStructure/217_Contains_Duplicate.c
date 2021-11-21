static int CompareFunction(const int * left, const int * right)
{ return (*left - *right); }

bool containsDuplicate(int* nums, int numsSize){
    qsort((void*)nums,numsSize,sizeof(int),CompareFunction);
    
    int i;
    for(i=0; i<numsSize-1; ++i)
        if(nums[i]==nums[i+1]) return true;
    
    return false;
}