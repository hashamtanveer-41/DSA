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
   int count1 =0;
void func15(TreeNode* root, int target, long long currSum, bool skipped) {
    if (root==nullptr)return;
    if (currSum + root->val == target)count1++;
    // Take current and make skipped to false, mean
    if (skipped) {
        func15(root->left, target, currSum+root->val, true);
        func15(root->right, target, currSum+root->val, true);
    }else {
        func15(root->left, target, currSum+root->val, true);
        func15(root->right, target, currSum+root->val, true);
        // Skip current value
        func15(root->left, target, currSum, false);
        func15(root->right, target, currSum, false);
    }
}
int pathSum(TreeNode* root, int targetSum) {
    // skipped will work like if you have taken current value you can skip its children, but if you skip one you have to skip everyone you have to take them
    // Chain cant be broken in sum
    long long sum = 0;
    func15(root, targetSum, sum, false);
    return count1;
}
};