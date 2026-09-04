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
int answer = INT_MIN;
   int findMaxPathSum(TreeNode* root){
    if(root==nullptr)return 0;
    int left = max(0,findMaxPathSum(root->left));
    int right = max(0, findMaxPathSum(root->right));
    answer = max(root->val+left+right, answer);
    return root->val+max(left, right);
}
int maxPathSum(TreeNode* root) {
    findMaxPathSum(root);
    return answer;
}
};