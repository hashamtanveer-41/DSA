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
    int answer = 0;
    int fun1(TreeNode* root) {
    if (root == nullptr)return 0;
    int left = fun1(root->left);
    int right = fun1(root->right);
    int sum = left+right;
    answer = max(answer, sum);
    return 1+max(left,right);
}
int diameterOfBinaryTree(TreeNode* root) {
    fun1(root);
    return answer;
}
};