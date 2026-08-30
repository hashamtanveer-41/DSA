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
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root==nullptr)return {};
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int lvlSize = q.size();
        vector<int> temp(lvlSize);
        int left=0;
        while (lvlSize--) {
            TreeNode* node = q.front();
            q.pop();
            temp[left]= (node->val);
            if (node->left!=nullptr)
                q.push(node->left);
            if (node->right!=nullptr)
                q.push(node->right);
            left++;
        }
        res.push_back(temp);
    }
    return res;
}
};