#define BIT(c) (int)( 1 << ( (int)(c) & 0x000F ) )

bool isValid(const char * check){
    int i;
    int reg = (int)0;
    for(i=0; i<9; ++i){
        if(check[i]=='.') continue;
        else if(BIT(check[i]) & reg) return false;
        else reg |= BIT(check[i]);
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int i;
    for(i=0; i<boardSize; ++i)
        if(!isValid(board[i])) return false;
    
    int j;
    char check[9];
    for(i=0; i<boardSize; ++i){
        for(j=0; j<9; ++j) check[j] = board[j][i];
        if(!isValid(check)) return false;
    }
    
    int k,p;
    for(k=0; k<3; ++k){
        for(p=0; p<3; ++p){
            for(i=0; i<3; ++i){
                for(j=0; j<3; ++j)
                    check[i*3+j] = board[k*3+i][p*3+j];
            }
            if(!isValid(check)) return false;
        }
    }
    
    return true;
}
