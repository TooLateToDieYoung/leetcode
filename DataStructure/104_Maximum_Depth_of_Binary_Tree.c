
int maxDepth(struct TreeNode * root){
    if(!root) return 0;
    int Deep_L = maxDepth(root->left ) + 1;
    int Deep_R = maxDepth(root->right) + 1;
    return (Deep_L > Deep_R) ? Deep_L : Deep_R;
}
