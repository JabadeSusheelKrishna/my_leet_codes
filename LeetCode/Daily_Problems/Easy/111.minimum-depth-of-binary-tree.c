/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    int l_depth = INT_MAX, r_depth = INT_MAX;
    
    if (root->left != NULL) {
        l_depth = minDepth(root->left);
    }
    if (root->right != NULL) {
        r_depth = minDepth(root->right);
    }
    if(l_depth < r_depth)
    {
        return l_depth + 1;
    }
    else
    {
        return r_depth + 1;
    }
}
