
int _cmp(const void * a, const void * b){ return *((int*)a) - *((int*)b); }

int _short(int * nums, const int size){
    int curr, record = 0;
    for(curr=1; curr < size; ++curr){
        if(nums[record] != nums[curr]){
            nums[++record] = nums[curr];
        }
    }
    return record + 1;
}

int * intersection(int * nums1, int nums1Size, int * nums2, int nums2Size, int * returnSize){
    qsort(nums1, nums1Size, sizeof(int), _cmp);
    qsort(nums2, nums2Size, sizeof(int), _cmp);
    nums1Size = _short(nums1, nums1Size);
    nums2Size = _short(nums2, nums2Size);
    
    *returnSize = 0;
    int curr1 = 0, curr2 = 0;
    while(curr1 < nums1Size && curr2 < nums2Size){
        
        if(nums1[curr1] == nums2[curr2]){ 
            ++(*returnSize);
            ++curr1;
            ++curr2;
            continue;
        }
        nums1[curr1] < nums2[curr2] ? ++curr1 : ++curr2;
        
    }
    
    curr1 = 0, curr2 = 0;
    int i = 0, * res = (int*)calloc(*returnSize, sizeof(int));
    while(curr1 < nums1Size && curr2 < nums2Size){
        
        if(nums1[curr1] == nums2[curr2]){ 
            res[i++] = nums1[curr1];
            ++curr1;
            ++curr2;
            continue;
        }
        nums1[curr1] < nums2[curr2] ? ++curr1 : ++curr2;
        
    }
    
    return res;
}
