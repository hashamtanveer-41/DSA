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
    unordered_map<int , int> in;
int idx = 0;
TreeNode* fun6(vector<int>& preorder, int low , int high ) {
    if (low>high)return nullptr;
    TreeNode* node = new TreeNode(preorder[idx]);
    idx++;
    int id = in[node->val];
    node->left = fun6(preorder, low, id-1);
    node->right = fun6(preorder, id+1, high);
    return node;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    for (int i =0; i<n; i++)in[inorder[i]]=i;
    int low = 0, high =n-1;
    return fun6(preorder, low, high); 
}
};