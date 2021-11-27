
int * twoSum(int * numbers, int numbersSize, int target, int * returnSize){
    
    int L = 0, R = numbersSize - 1, Sum = numbers[L] + numbers[R];

    while( Sum  != target ){
        Sum < target ? ++L : --R;
        Sum = numbers[L] + numbers[R];
    }
    
    int * res = (int*)calloc(*returnSize = 2, sizeof(int));
    res[0] = L + 1;
    res[1] = R + 1;
    
    return res;
}