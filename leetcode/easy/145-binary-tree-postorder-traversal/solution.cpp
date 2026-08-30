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
void func3(TreeNode* node, vector<int>& res) {
    if (node==nullptr)return;
    func3(node->left, res);
    func3(node->right, res);
     res.push_back(node->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    func3(root, result);
    return result;
}
};