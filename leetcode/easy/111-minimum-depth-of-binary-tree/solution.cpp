/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fun8(TreeNode* root) {
    if (root==nullptr)return 0;
    if (root->right==nullptr) {
        int left = fun8(root->left);
        return 1+left;
    }
    if (root->left==nullptr) {
        int right = fun8(root->right);
        return 1+right;
    }
    int left = fun8(root->left);
    int right = fun8(root->right);
    return 1+min(left, right);
}
int minDepth(TreeNode* root) {
int ans = fun8(root);
    return ans;
}
};