/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** matrixReshape(int** mat, int m, int* n, int r, int c, int* returnSize, int** returnColumnSizes){
    
    int i, rows, cols, ** ans;
    
    if(r*c == m*(*n)){
        rows = r;
        cols = c;
    }
    else{
        rows = m;
        cols = *n;
    }

    ans = (int**)malloc(rows * sizeof(int*));
    *returnSize = rows;
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for(i=0; i<rows; ++i){
        ans[i] = (int*)malloc(cols * sizeof(int));
        (*returnColumnSizes)[i] = cols;
    }
    
    for(i=0; i<rows*cols; ++i)
        ans[i/cols][i%cols] = mat[i/(*n)][i%(*n)];
    
    return ans;
}
