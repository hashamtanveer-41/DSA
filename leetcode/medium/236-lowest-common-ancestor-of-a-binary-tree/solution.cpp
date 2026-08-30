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
    TreeNode* res = nullptr;
int func5(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root==nullptr)return 0;
    int left = func5(root->left, p, q);
    int right = func5(root->right, p, q);
    int self = 0;
    if (root->val==p->val||root->val==q->val) {
        self++;
    }

    int total = right +left+self;
    if (total==2 && res==nullptr)res= root;
    return total;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    func5(root, p, q);
    return res;
}
};