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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root==nullptr)return {};
    queue<TreeNode*> q;
    int leftToRight = 1;
    q.push(root);
    while (!q.empty()) {
        int lvlSize = q.size();
        vector<int> temp(lvlSize);
        int left=0, right = lvlSize-1;
        while (lvlSize--) {
            TreeNode* node = q.front();
            q.pop();
            if (leftToRight) {
                temp[left]= (node->val);
                left++;
            }else {
                temp[right]= (node->val);
                right--;
            }
            if (node->left!=nullptr)
                q.push(node->left);
            if (node->right!=nullptr)
                q.push(node->right);
        }
        res.push_back(temp);
        leftToRight = 1- leftToRight;
    }
    return res;
}
};