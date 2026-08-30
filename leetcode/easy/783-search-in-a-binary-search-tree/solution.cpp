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
    TreeNode* ans = nullptr;
void func5(TreeNode* root, int val) {
    if (root==nullptr)return;
    if (root->val==val) {
        ans = root;
        return;
    }
    if (root->val>val) 
        func5(root->left, val);
    else 
        func5(root->right, val);
}
TreeNode* searchBST(TreeNode* root, int val) {
    func5(root, val);
    return ans;
}
};