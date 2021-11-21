bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i, j;
    for(i=0; i<matrixSize; ++i)
        for(j=0; j<matrixColSize[i]; ++j)
            if(target==matrix[i][j]) return true;
    return false;
}
