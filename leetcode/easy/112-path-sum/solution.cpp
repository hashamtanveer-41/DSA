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
    bool result = false;
void func8(TreeNode* root, int sum , int target) {
    if (root==nullptr) return;
    sum += root->val;
    if (root->left==nullptr && root->right == nullptr) {
        if (sum==target) {
            result = true;
            return;
        };
    }
    func8(root->left, sum, target);
    func8(root->right, sum , target);
    return;
}
bool hasPathSum(TreeNode* root, int targetSum) {
 int sum =0;
    func8(root, sum , targetSum);
    return result;
}
};