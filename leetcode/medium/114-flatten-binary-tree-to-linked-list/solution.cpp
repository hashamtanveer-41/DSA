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
TreeNode* rearrangeToLL(TreeNode *root, TreeNode *&prev){
        if(!root) return nullptr;

        TreeNode *right = rearrangeToLL(root->right, prev);
        TreeNode *left = rearrangeToLL(root->left, prev);

        root->right = prev;
        root->left = nullptr;
        prev = root;
        return root;
    }
    void flatten(TreeNode* root) {
        TreeNode *prev = nullptr;
        rearrangeToLL(root, prev);
    }
};