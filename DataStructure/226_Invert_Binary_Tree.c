
typedef struct TreeNode tree_t;

tree_t * invertTree(tree_t * root){
    if(!root) return root;
    tree_t * temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left );
    invertTree(root->right);
    return root;
}