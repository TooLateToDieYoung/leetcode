typedef struct TreeNode tree_t;

int CompareNodes(const tree_t * L, const tree_t * R){
    
    if(L == NULL && R != NULL) return 1;
    if(L != NULL && R == NULL) return 1;
    if(L == NULL && R == NULL) return 0;
    if(L->val != R->val) return 1;
    
    return CompareNodes(L->left, R->right) | CompareNodes(R->left, L->right);
}

bool isSymmetric(const tree_t * root){
    if(root == NULL) return true;
    return CompareNodes(root->left, root->right) == 0;
}
