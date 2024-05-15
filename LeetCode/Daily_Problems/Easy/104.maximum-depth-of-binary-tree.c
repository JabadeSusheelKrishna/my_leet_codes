/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    int max_depth = 0;
    if(left_depth > right_depth)
    {
        max_depth = left_depth;
    }
    else
    {
        max_depth = right_depth;
    }
    return ++max_depth;
}
