
typedef struct TreeNode tree_t;

/* First Trying Runtime = 20ms */
tree_t * searchBST(const tree_t * root, const int val){
    if(root == NULL) return root;
    if(root->val == val) return root;
    
    tree_t * temp;
    temp = searchBST(root->left,  val);
    if(temp != NULL) return temp;
    temp = searchBST(root->right, val);
    if(temp != NULL) return temp;
    
    return NULL;
}

/* Second Trying Runtime = 16ms */
tree_t * searchBST(const tree_t * root, const int val){
    
    if(root == NULL) return root;
    if(root->val == val) return root;
    tree_t * temp;
    
    if(root->val > val) temp = searchBST(root->left, val);
    else temp = searchBST(root->right, val);
    
    if(temp != NULL) return temp;
    else return NULL;
}