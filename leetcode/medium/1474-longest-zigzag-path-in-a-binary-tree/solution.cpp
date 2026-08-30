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
    int func16(TreeNode* root, bool right, int nodes) {
    if (root==nullptr)return nodes - 1;
    // Go to left 
    // If i want to go left but my left is already true which means right is false then i have to reset my counter
    // If not then i can go to right
    // Go to right
    // If my right is true then it means that i have to reset the counter and move to right
    // Otherwise i have to move left and continue the process
    if (right) {
        // If right is true then my parent took right move to reach here i can either continue to left
        int c1 = func16(root->left, false, nodes+1);
        // and reset counter to 1 and move again right
        int c2 = func16(root->right, true, 1);
        return max(c1, c2);
    }else {
        // My right is false, so i can move right with continuation and left with new start
        int c1 = func16(root->right, true, nodes+1);
        int c2 = func16(root->left, false, 1);
        return max(c1, c2);
    }
}
int longestZigZag(TreeNode* root) {
    if (root==nullptr)return 0;
    int left = func16(root->left, false, 1);
    int right = func16(root->right, true, 1);
    return max(left, right);
}
};