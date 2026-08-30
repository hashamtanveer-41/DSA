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
    int value = 0;
void func14(TreeNode* root, int prev) {
    if (root==nullptr)return;
    if (root->val>=prev)value++;
    func14(root->left, max((root->val),prev ));
    func14(root->right, max((root->val),prev ));
}
int goodNodes(TreeNode* root) {
    func14(root, INT_MIN);
    return value;
}
};