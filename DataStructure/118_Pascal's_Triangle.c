/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    
    int i, j, ** ans = (int**)malloc(numRows*sizeof(int*));
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows*sizeof(int));
    for(i=0; i<numRows; ++i){
        ans[i] = (int*)malloc((i+1)*sizeof(int));
        (*returnColumnSizes)[i] = (i+1);
    }
    
    for(i=0; i<numRows; ++i){
        for(j=0; j<i+1; ++j){
            if(j==0||j==i) ans[i][j] = 1;
            else ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    
    return ans;
}
