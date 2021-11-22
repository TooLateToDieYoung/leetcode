
typedef struct TreeNode tree_t;

//Do not use this for counting Tree's depth, because it takes more time.
//#define MAX(X,Y) ( ( (X) > (Y) ) ? (X) : (Y) )

int TreeDepth(tree_t * self){
    if (!self) return 0;
    int DepthL = TreeDepth(self->left)  + 1;
    int DepthR = TreeDepth(self->right) + 1;
    return DepthL > DepthR ? DepthL : DepthR;
    //return MAX(DepthL,DepthR); it wastes source. ( 4ms -> 17ms )
}
// The following code have the same effect as the above ones.
// But don't replace the above ones with it.
//{ return (self) ? MAX(TreeDepth(self->left),TreeDepth(self->right)) + 1 : 0; }
// To save the variables when calling recursion function.
// It's able to avoid to take unnecessary calculation.
// 遞迴最好將變數暫存起來，否則每次都重算會太耗時

int * ReallocArray(int * arr, const int newSize){
    int * old = arr;
    arr = (int*)malloc(newSize * sizeof(int));
    
    if(arr) for(int i=0; i<newSize-1; ++i) arr[i] = old[i];
    
    if(old) free(old);
    
    return arr;
}

void _LevelOrder(const tree_t * self, int ** ans, int * size, const int deep){
    if(!self) return;
    ans[deep] = ReallocArray(ans[deep], size[deep] + 1);
    ans[deep][size[deep]++] = self->val;
    _LevelOrder(self->left,  ans, size, deep + 1);
    _LevelOrder(self->right, ans, size, deep + 1);
}

int ** levelOrder(tree_t * root, int * returnSize, int ** returnColumnSizes){
    if(!root){
        *returnSize = 0;
        *returnColumnSizes = (int*)malloc(0);
        return (int**)malloc(0);
    }
    
    *returnSize = TreeDepth(root);
    *returnColumnSizes = (int*)calloc( (*returnSize), sizeof(int) );
    int ** ans = (int**)calloc( (*returnSize), sizeof(int*) );
    
    _LevelOrder(root, ans, *returnColumnSizes, 0);
    
    return ans;
}
