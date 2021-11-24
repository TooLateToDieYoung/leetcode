/* First Trying Runtime = 30ms, Memory less than 99.97% */
int majorityElement(int* nums, int numsSize){
    unsigned i, check, counter = 0;
    int result = 0;
    
    for(check = 1; check; check <<= 1, counter &= 0){ // Check each bit  
        
        for(i = 0; i < numsSize; ++i) // compare all nums
            if( check & nums[i] ) ++counter; // if this bit set, then counter + 1
        
        // if counter > (n/2) that means this bit is set in majority.
        if( counter > ( numsSize >> 1 ) ) result |= check;
    }
    
    return result;
}

/* Second Trying Runtime = 20ms, Memory less than 15.18% */
int _cmp(int * a, int * b) { return *a - *b; }

int majorityElement(int* nums, int numsSize){
    
    qsort(nums, numsSize, sizeof(int), _cmp);
    
    return *( nums + (numsSize >> 1) );
}