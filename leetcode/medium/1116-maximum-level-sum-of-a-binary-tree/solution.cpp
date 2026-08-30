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
    int maxLevelSum(TreeNode* root) {
        if (root==nullptr)return {};
    queue<pair<TreeNode*, int>> q;
    int res = 0,maxSum = INT_MIN;
    q.push({root, 1});
    while (!q.empty()) {
        int lvlSize = q.size();
        int currSum = 0;
        int level = q.front().second;
        for (int i = 0; i<lvlSize; i++){
            TreeNode* node = q.front().first;
            int lvl = q.front().second;
            currSum += node->val;
            q.pop();
            if (node->right!=nullptr)
                q.push({node->right, lvl+1});
            if (node->left!=nullptr)
                q.push({node->left, lvl+1});
        }
        if (currSum>maxSum) {
            res = level;
            maxSum = currSum;
        }
    }
    return res;
    }
};