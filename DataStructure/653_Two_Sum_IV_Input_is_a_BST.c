
typedef struct TreeNode tree_t;

int TreeSize(const tree_t * const self)
{ return (self) ? TreeSize(self->left) + TreeSize(self->right) + 1 : 0; }

int * GetDataFromTree(const tree_t * const self, int * curr){
    *curr++ = self->val;
    if(self->left ) { curr = GetDataFromTree(self->left,  curr); }
    if(self->right) { curr = GetDataFromTree(self->right, curr); }
    return curr;
}

bool findTarget(const tree_t * const root, const int target){
    if(root == NULL) return false;
    
    bool  ans = false;
    int i, j, size = TreeSize(root);
    int * arr = (int*)calloc(size, sizeof(tree_t));
    int * curr = arr;
    
    GetDataFromTree(root, curr);
    
    for(i=0; i<size; ++i){
        for(j=i+1; j<size; ++j){
            if(arr[i]+arr[j] == target){
                ans = true;
                break;
            }
        }
        if(ans) break;
    }
    
    free(arr);
    
    return ans;
}