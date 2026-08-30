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
TreeNode* previous = nullptr;
bool ans1 = true;
    void fun3(TreeNode* root) {
    if (root==nullptr) return;
    fun3(root->left);
    if (previous==nullptr)previous = root;
    else {
        if (root->val<=previous->val) {
            ans1 = false;
        }
        previous = root;
    }
    fun3(root->right);
}
bool isValidBST(TreeNode* root) {
    fun3(root);
    return ans1;
}
};