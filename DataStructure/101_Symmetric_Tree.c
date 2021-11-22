typedef struct TreeNode tree_t;

int CompareRightNodes(const tree_t * L, const tree_t * R){
    
    if(L == NULL && R != NULL) return 1;
    if(L != NULL && R == NULL) return 1;
    if(L == NULL && R == NULL) return 0;
    if(L->val != R->val) return 1;
    
    return CompareRightNodes(L->left, R->right) | CompareRightNodes(R->left, L->right);
}

bool isSymmetric(const tree_t * root){
    if(root == NULL) return true;
    return CompareRightNodes(root->left, root->right) == 0;
}