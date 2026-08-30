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
    vector<vector<int>> result1;
void func9(TreeNode* root, int target, vector<int> sum, int currSum) {
    if (root==nullptr) return;
    currSum+=root->val;
    sum.push_back( root->val);
    if (root->left==nullptr && root->right == nullptr) {
        if (currSum==target) {
            result1.push_back(sum);
            return;
        };
    }
    func9(root->left, target, sum, currSum);
    func9(root->right, target , sum, currSum);
    return;
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int>sum;
    int currSum=0;
    func9(root, targetSum,sum, currSum );
    return result1;
}
};