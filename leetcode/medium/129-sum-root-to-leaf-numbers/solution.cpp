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
    int answer =0;
void func10(TreeNode* root, int sum) {
    if (root==nullptr) return;
    sum = sum*10+ root->val;
    if (root->left==nullptr && root->right == nullptr) {
            answer += sum;
            return;
    }
    func10(root->left, sum);
    func10(root->right, sum);
    return;
}
int sumNumbers(TreeNode* root) {
    int sum = 0;
    func10(root, sum);
    return answer;
}
};