
typedef struct TreeNode tree_t;

tree_t * sortedArrayToBST(int* nums, int numsSize){
    
    if(numsSize == 0) return NULL;
    
    int middle = numsSize >> 1;
    
    tree_t * root = (tree_t*)calloc(1, sizeof(tree_t));
    
    root->val   = nums[middle];
    root->left  = sortedArrayToBST(&nums[0],          middle               );
    root->right = sortedArrayToBST(&nums[middle + 1], numsSize - middle - 1);
    
    return root;
}
