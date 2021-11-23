
typedef struct TreeNode tree_t;

tree_t * lowestCommonAncestor(tree_t * root, tree_t * p, tree_t * q){
    
    if(root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left,  p, q);
    
    if(root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    
    return root;
}