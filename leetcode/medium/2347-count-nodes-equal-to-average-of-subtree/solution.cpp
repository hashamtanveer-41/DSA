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
int count1 = 0;
    pair<int, int> findAverageOfSubtree(TreeNode* root) {
    if (root==nullptr) {
        return {0, 0};
    }
    if (root->left==nullptr && root->right == nullptr) {
        count1++;
        return {root->val, 1};
    }
    pair<int, int> left = findAverageOfSubtree(root->left);
    pair<int, int> right = findAverageOfSubtree(root->right);
    int sum = root->val + left.first +right.first;
    int nodes = left.second + right.second +1;
    if (sum/nodes == root->val)
        count1++;
    return {sum, nodes};
}
int averageOfSubtree(TreeNode* root) {
    findAverageOfSubtree(root);
    return count1;
}

};