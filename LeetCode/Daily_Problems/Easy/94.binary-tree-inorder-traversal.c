/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* curr, int** res, int* resSize) {
    struct TreeNode* pre;
    while (curr != NULL) {
        if (curr->left == NULL) {
            *res = realloc(*res, sizeof(int) * (++(*resSize)));
            (*res)[*resSize - 1] = curr->val;
            curr = curr->right;  // move to next right node
        } else {                 // has a left subtree
            pre = curr->left;
            while (pre->right != NULL) {  // find rightmost
                pre = pre->right;
            }
            pre->right = curr;             // put cur after the pre node
            struct TreeNode* temp = curr;  // store cur node
            curr = curr->left;  // move curr to the top of the new tree
            temp->left =
                NULL;  // original cur left be null, avoid infinite loops
        }
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int));
    *returnSize = 0;
    inorder(root, &res, returnSize);
    return res;
}
