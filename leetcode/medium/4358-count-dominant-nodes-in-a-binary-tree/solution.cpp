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
    int result2 = 0;
int findDom(TreeNode* root) {
    if (root==nullptr) return 0;
    if (root->left==nullptr && root->right==nullptr) {
        result2++;
        return root->val;
    }

    int left = findDom(root->left);
    int right = findDom(root->right);
    int maxVal= max(left, right);
    if (root->val>=maxVal)result2++;
    return max(maxVal,root->val );
}
int countDominantNodes(TreeNode* root) {
    findDom(root);
    return result2;
}
};