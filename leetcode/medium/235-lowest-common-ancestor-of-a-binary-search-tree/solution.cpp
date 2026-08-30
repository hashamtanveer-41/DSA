/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode* ans = nullptr;

    void func6(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root==nullptr)return;
    if (root==p||root==q) {
        ans = root;
        return;
    }
    if (root->val<p->val) {
        func6(root->right, p, q);
    }else if (root->val>q->val)
        func6(root->left, p, q);
    else {
        ans = root;
        return;
    }
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val<q->val) {
        func6(root, p, q);
    }else {
        func6(root, q, p);
    }
    return ans;
}
};