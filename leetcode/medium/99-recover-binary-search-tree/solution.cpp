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
TreeNode* previous = nullptr;
    TreeNode* g1First= nullptr;
TreeNode* g1Second= nullptr;
TreeNode* g2First= nullptr;
TreeNode* g2Second= nullptr;
int ghalti= 0;
void fun4(TreeNode* root) {
    if (root==nullptr) return;
    fun4(root->left);
    if (previous==nullptr)previous = root;
    else {
        if (root->val<previous->val) {
            if (ghalti==0) {
                g1First = previous;
                g1Second = root;
                ghalti++;
            }else {
                g2First = previous;
                g2Second = root;
                ghalti++;
            }
        }
        previous = root;
    }
    fun4(root->right);
}
void recoverTree(TreeNode* root) {
    fun4(root);
    if (ghalti==1) {
        swap(g1First->val, g1Second->val);
    }else {
        swap(g1First->val, g2Second->val);
    }
}
};